# APP7_Qt
Projet d'interface avec Qt

Interface Controleur Garduino:

Affiche toujours les données suivantes:

	-Le taux d'humidité du substrat.
	-Le taux de luminosité naturelle.
	-Les heures de lumière naturelle reçue dans la journée.
	-Température du substrat, de l'eau et de l'air.
	-Le Ph du sol et de l'eau.
	-Le niveau de l'eau dans le réservoir.
	
	
Actions:

	- Bouton de choix de mode de fonctionnement:
	
		-Automatique
			En mode automatique, des données sont entrés dans les espaces appropriés afin de determiner les valeurs des 
			senseurs que nous désirons obtenir. (Puisque les 2 mode sont dans la même fenêtre, les options du mode choisi 				seront disponibles, mais celles de l'autre seront vérrouillés)
		-Manuel
			En mode manuel, on peut démarrer la lumière et la pompe durant un choix de périodes. (Puisque les 2 mode sont 				dans la même fenêtre, les options du mode choisi seront disponibles, mais celles de l'autre seront vérrouillés)
	
	- Bouton "Arrêt d'urgence" visible en tout temps
		Arrête immédiatement la pompe et la lumière. (Mode manuel avec paramètre de lumière et pompe éteintes)
	
	- Menu Fichier-> Ouvrir:
		Permet à l'utilisateur d'ouvrir une configuration existente.
		
	- Menu Fichier-> Enregistrer:
		Permet à l'utilisateur d'enregistrer la configuration actuelle.
		
	- Menu Fichier-> Arrêt:
		Arrête immédiatement la pompe et la lumière. (Mode manuel avec paramètre de lumière et pompe éteintes)
		
	- Menu Fichier-> Démarrer:
		Débute le programme avec les paramètres choisis.
		
	- Menu Fichier-> Quitter:
		Ferme l'application.
		
	- Menu Aide-> Manuel d'utilisation:
		Ouvre une page fournissant la documentation nécessaire .
		
	-Bouton Démarrer:
		Débute le programme avec les paramètres choisis.
		
	-Bouton Annuler:
		Annule les changements du programme.
		
	-Boutons sélecteurs de temps d'activation de la pompe (Mode manuel):
		Permet à l'usager de choisir une période pour l'activation de la pompe.		
	
	-Boutons sélecteurs de temps d'activation de la lumière (Mode manuel):
		Permet à l'usager de choisir une période pour l'activation de la lumière.
		
	-Champs de configuration du mode automatique:
		-Champ pour indiquer l'humidité désiré dans le substrat ou l'on peut aussi cliquer sur les flèches (haut/bas)pour 			 choisir.
		-Champs pour indiquer la période de luminosité désirée ou double "slider" qui permet de la choisir avec la souris.
		-Champs pour indiquer les températures minimale et maximale désirées ou double "slider" qui permet de les choisir avec 			 la souris.
	-Barre de statut:
		Confirme les actions effectués par l'utilisateur lors de la première itération mais servira plutôt à confirmer à 			l'utilisateur que l'action à bien été effectuée.
		



//Version Ultimate pourrait Ouvrir une Fenêtre Jardin (grille) et associer une configuration à chaque section. De plus, il pourrait y avoir des modèles pré-configurés pour chaque plante.
		
		
