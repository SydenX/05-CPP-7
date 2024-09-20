#!/bin/bash

# Vérification du nombre d'arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <dossier> <nom>"
    exit 1
fi

# Vérification si le dossier existe
if [ ! -d "$1" ]; then
    echo "Le dossier $1 n'existe pas."
    exit 1
fi

# Se déplacer vers le dossier
cd "$1" || exit 1

lowercase=$(echo "$2" | tr '[:upper:]' '[:lower:]')
uppercase=$(echo "$2" | tr '[:lower:]' '[:upper:]')

# Création du fichier .hpp
touch "$2.hpp"
echo "" > "$2.hpp"
echo "#ifndef $uppercase""_HPP" >> "$2.hpp"
echo "# define $uppercase""_HPP" >> "$2.hpp"
echo "" >> "$2.hpp"
echo "#include <iostream>" >> "$2.hpp"
echo "" >> "$2.hpp"
echo "class $2 {" >> "$2.hpp"
echo "	private:" >> "$2.hpp"
echo "		" >> "$2.hpp"
echo "	protected:" >> "$2.hpp"
echo "		" >> "$2.hpp"
echo "	public:" >> "$2.hpp"
echo "		$2();" >> "$2.hpp"
echo "		~$2();" >> "$2.hpp"
echo "		$2($2 const &$lowercase);" >> "$2.hpp"
echo "		$2& 	operator=($2 const&);" >> "$2.hpp"
echo "};" >> "$2.hpp"
echo "" >> "$2.hpp"
echo "#endif" >> "$2.hpp"

# Création du fichier .cpp
touch "$2.cpp"
echo "" > "$2.cpp"
echo "#include \"$2.hpp\"" >> "$2.cpp"
echo "" >> "$2.cpp"
echo "//Constructor" >> "$2.cpp"
echo "$2::$2() {" >> "$2.cpp"
echo "}" >> "$2.cpp"
echo "" >> "$2.cpp"
echo "//Destructor" >> "$2.cpp"
echo "$2::~$2() {" >> "$2.cpp"
echo "}" >> "$2.cpp"
echo "" >> "$2.cpp"
echo "//Copy-Constructor" >> "$2.cpp"
echo "$2::$2($2 const &$lowercase) {" >> "$2.cpp"
echo "	*this = $lowercase;" >> "$2.cpp"
echo "}" >> "$2.cpp"
echo "" >> "$2.cpp"
echo "//Copy-Assignment Operator Overload" >> "$2.cpp"
echo "$2&	$2::operator=($2 const &$lowercase){" >> "$2.cpp"
echo "" >> "$2.cpp"
echo "	return *this;" >> "$2.cpp"
echo "}" >> "$2.cpp"
echo "" >> "$2.cpp"

echo "Fichiers $2.hpp et $2.cpp créés dans le dossier $1."
