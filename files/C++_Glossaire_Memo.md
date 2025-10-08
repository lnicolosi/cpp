# 📘 Glossaire C++ – Mémo Visuel

## 📦 Classe
Structure qui décrit un objet : ses données (attributs) et ses actions (méthodes).

## 🔹 Objet
Instance concrète d'une classe.

## 🛠️ Méthode
Fonction qui appartient à une classe. Elle agit sur un objet.

## 🎒 Attribut / Membre
Variable déclarée dans une classe, propre à chaque objet.

## 🏗️ Constructeur
Fonction spéciale appelée automatiquement à la création d’un objet.

## 🧨 Destructeur
Fonction spéciale appelée automatiquement à la destruction d’un objet.

## 📋 Constructeur de copie
Crée un nouvel objet en copiant un autre.

## 📤 Opérateur d’affectation
Permet de copier un objet déjà existant dans un autre.

## 🎭 Polymorphisme
Permet d’utiliser des objets de différentes classes via un même pointeur, avec appel automatique de la bonne méthode.

## ✏️ Redéfinition (override)
Quand une classe enfant réécrit une méthode héritée du parent.

## 🧠 Méthode virtuelle
Méthode marquée avec `virtual` pour permettre un comportement dynamique (polymorphisme).

## 🚫 Méthode virtuelle pure
Méthode sans corps (`= 0`) → rend la classe abstraite.

## 🏛️ Classe abstraite
Classe avec au moins une méthode virtuelle pure. Impossible à instancier directement.

## 🧬 Héritage
Permet à une classe de reprendre le code d’une autre (classe mère).

## ✂️ Slicing
Quand un objet enfant est copié dans un parent → perte de ses spécificités.

## 🔐 Encapsulation
Cacher les données internes d’un objet via `private`/`protected`, accès via getters/setters.

## 🪪 Accesseurs (getters/setters)
Méthodes pour accéder ou modifier des attributs privés.

## 🚪 public / protected / private
Contrôle d’accès :  
- `public` → accessible partout  
- `protected` → accessible depuis la classe et ses enfants  
- `private` → accessible uniquement dans la classe

## 📍 this
Pointeur vers l’objet courant dans une méthode membre.

## 🧹 Deep copy
Copie en profondeur (y compris les pointeurs), évite les partages d’adresse mémoire.

## 📋 Liste d’initialisation
Initialisation directe des attributs dans l’en-tête du constructeur.
