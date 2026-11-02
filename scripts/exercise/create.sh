#!/usr/bin/env bash

set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
ROOT_CMAKE="$ROOT_DIR/CMakeLists.txt"

usage() {
    local script_name
    script_name="$(basename "$0")"

    cat <<EOF
Uso: $script_name [-u UNITA] [-e ESERCIZIO]

  -u UNITA      numero dell'unità (default: l'ultima esistente)
  -e ESERCIZIO  numero dell'esercizio (default: il successivo all'ultimo dell'unità)
  -h            mostra questo aiuto

Esempi:
  $script_name              ultima unità, prossimo esercizio
  $script_name -u 3         unit3, prossimo esercizio (crea unit3 se non esiste)
  $script_name -u 2 -e 7    unit2/es7
  $script_name -e 7         ultima unità, es7
EOF
}

fail() {
    echo "Errore: $1" >&2
    exit 1
}

find_last_number() {
    local parent="$1"
    local prefix="$2"
    local highest=-1
    local dir name number

    for dir in "$parent"/"$prefix"*/; do
        name="$(basename "$dir")"
        [[ "$name" =~ ^${prefix}([0-9]+)$ ]] || continue
        number=$((10#${BASH_REMATCH[1]}))
        if (( number > highest )); then
            highest=$number
        fi
    done

    echo "$highest"
}

parse_number() {
    local value="${1#"$2"}"

    if [[ ! "$value" =~ ^[0-9]+$ ]] || (( 10#$value == 0 )); then
        fail "'$1' non è un numero valido per $2 (es. 3 oppure ${2}3)"
    fi

    echo $((10#$value))
}

unit_option=""
exercise_option=""

while getopts ":u:e:h" option; do
    case "$option" in
        u) unit_option="$OPTARG" ;;
        e) exercise_option="$OPTARG" ;;
        h) usage; exit 0 ;;
        :) fail "-$OPTARG richiede un valore" ;;
        *) usage >&2; exit 1 ;;
    esac
done
shift $((OPTIND - 1))

if (( $# > 0 )); then
    usage >&2
    exit 1
fi

[[ -f "$ROOT_CMAKE" ]] || fail "CMakeLists.txt di root non trovato in $ROOT_DIR"

if [[ -n "$unit_option" ]]; then
    unit_number="$(parse_number "$unit_option" unit)"
else
    unit_number="$(find_last_number "$ROOT_DIR" unit)"
    (( unit_number >= 0 )) || fail "nessuna cartella unitN in $ROOT_DIR, indica l'unità con -u"
fi

unit="unit$unit_number"
unit_dir="$ROOT_DIR/$unit"

if [[ -n "$exercise_option" ]]; then
    exercise_number="$(parse_number "$exercise_option" es)"
else
    last_exercise_number="$(find_last_number "$unit_dir" es)"
    exercise_number=$(( last_exercise_number < 0 ? 1 : last_exercise_number + 1 ))
fi

new_exercise="es$exercise_number"
new_exercise_dir="$unit_dir/$new_exercise"
new_exercise_path="$unit/$new_exercise"
target_name="${unit}_${new_exercise}"

[[ ! -e "$new_exercise_dir" ]] || fail "$new_exercise_path esiste già"
[[ ! -e "$unit_dir" || -d "$unit_dir" ]] || fail "$unit esiste ma non è una cartella"

if [[ ! -d "$unit_dir" ]]; then
    echo "Creata nuova unità $unit"
fi

mkdir -p "$new_exercise_dir"

cat > "$new_exercise_dir/main.c" <<'EOF'
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    return 0;
}
EOF

printf 'add_executable(%s main.c)\n' "$target_name" > "$new_exercise_dir/CMakeLists.txt"

echo "Creato $new_exercise_path (target $target_name)"

if grep -Eiq "^[[:space:]]*add_subdirectory[[:space:]]*\([[:space:]]*${new_exercise_path}[[:space:]]*\)" "$ROOT_CMAKE"; then
    echo "add_subdirectory($new_exercise_path) è già nel CMakeLists.txt di root"
elif grep -Eiq '^[[:space:]]*add_subdirectory[[:space:]]*\(' "$ROOT_CMAKE"; then
    tmp_file="$(mktemp)"
    awk -v new_line="add_subdirectory($new_exercise_path)" '
        { lines[NR] = $0 }
        tolower($0) ~ /^[[:space:]]*add_subdirectory[[:space:]]*\(/ { last_match = NR }
        END {
            for (i = 1; i <= NR; i++) {
                print lines[i]
                if (i == last_match) print new_line
            }
        }
    ' "$ROOT_CMAKE" > "$tmp_file"
    cat "$tmp_file" > "$ROOT_CMAKE"
    rm -f "$tmp_file"
    echo "Aggiunto add_subdirectory($new_exercise_path) al CMakeLists.txt di root"
else
    echo "Attenzione: il CMakeLists.txt di root non usa add_subdirectory, quindi non l'ho modificato." >&2
    echo "Aggiungi tu il nuovo esercizio come sono aggiunti gli altri." >&2
fi