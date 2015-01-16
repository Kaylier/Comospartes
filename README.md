# Assistance gravitationnelle : Présentation
Ce projet est réalisé dans le cadre d'un [TIPE](https://fr.wikipedia.org/wiki/Travail_d%27initiative_personnelle_encadr%C3%A9) du lycée Blaise Pascal à Clermont Ferrand.

Il y a ici sources en C++ d'un programme permettant de prévoir les trajectoires idéales d'un satellite dans l'espace afin d'aller d'un point à un autre. Celles-ci sont commentées afin de faciliter la lecture aux participants du projet et non dans un but explicatif. Toutefois, si vous souhaitez une explication sur un certain point, vous êtes libre de nous contacter.

## Vue d'ensemble
Le projet tourne autours de l'étude de la trajectoire d'un satellite envoyé dans l'espace. Le programme en question recherche la meilleure trajectoire afin de tirer profit au maximum de l'effet d'assistance gravitationnelle, c'est à dire de profiter au mieux de l'attraction des planètes pour modifier la trajectoire et la vitesse. Il va chercher la condition initiale idéale pour s'approcher au maximum d'une orbite pré-définie suite à un laché en chute libre sans ajustement de trajectoire.

## Problématique
Comment optimiser la trajectoire en minimisant les ressources energetiques necessaires à l'ajustement ?

## Programme
Le programme se découpe en plusieurs 'modules' :
* Outils (vecteurs de coordonnées, planetes, ...)
* Situation (gere les positions des planètes au cours du temps de facon dynamique, incorpore une synchronisation avec une base de donnée ?)
* Objectif (fonction qui à une position et une vitesse associe un réel qui sera minimal pour un état idéal)
* Calcul d'une trajectoire à partir d'une dynamique initiale
* Recherche de la meilleure trajectoire
* Affichage

### Codé et débugué
* (Outil) Vecteurs de n coordonnées
* (Outil) Objet Planete
* (Outil) Objets Cinématique et Dynamiques
* Objectif
* Situation

### Codé et non débugué
* Fonction de calcul de trajectoire
* Enregistrement d'une image en svg

### En cours de codage
* Optimisation de la trajectoire

### Non commencé
* systeme de synchronisation des positions avec base de donnée

## Avenir
* Peut-être synchroniser régulièrement la position des planètes calculées avec une base de donnée (de l'ESA ou de la NASA) afin de gagner de la précision
* Rajouter une possibilité d'ajustement de la trajectoire en cours de route (actuellement le calcul se fait en chute libre)
* S'occuper de la visualisation
* Si le systeme est trop chaotique, il faut trouver une solution viable

# Informations techniques
Le programme est intégralement codé en C++
## Bibliothèques
L'enregistrement des images svg se fait via [simple-svg](https://code.google.com/p/simple-svg/) sous license [New BSD](opensource.org/licenses/BSD-3-Clause)
## License
License BSD
