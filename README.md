# projet-tut-cpp
									Jeux en lui même

Questions : 
	-Mode solo ou mode multijoueur ?
	-Si mode multijoueur combien de joueur ? 2
	-Génération de bloc de brique aléatoire ou prégénéré ?
	-Spawn du (des) joueur(s) (mobs) défini de manière aléatoire ou prédéfinie ?




Règles du bomberman :
	
	-Une entitée touchée par une bombe est détruite
	-Si une entitée est détruite alors il peut y avoir un bonus qui spawn
	-le jeux est fini si le joueur est mort ou si il n'y a plus que le joueur qui est sur le terrain
	-Seul le bomberman peut poser des bombes
	-Le joueur est mort si il est touché par un mob ( uniquement en mode solo )
	-Deplacement uniquement en vertical ou en horizontal, pas de diagonale
	-Un joueur ne peut pas traverser un bloc de brique


Liste des entités : 

	-Le(s) joueur(s)
	-Un ennemi (mob)
	-Un bloc de brique
	-Bonus

Liste des bonus principaux : 

	- +1 à la puissance (flamme)
	- +1 au nombre de bombe (bombe)
	- +1 en vitesse de déplacement (roller)

Liste des mobs principaux (si solo): 

	-Slime (monstre de base se déplaçant lentement)
	-Fantome (déplacement plus rapide que le slime)




Matrice pour le pattern de la map

3	3	3	3	3	3	3	3	3	3	3
3	1	2	1	2	1	2	1	2	1	3
3	2	3	2	3	2	3	2	3	2	3
3	1	2	1	2	1	2	1	2	1	3
3	2	3	2	3	2	3	2	3	2	3
3	1	2	1	2	1	2	1	2	1	3
3	2	3	2	3	2	3	2	3	2	3
3	1	2	1	2	1	2	1	2	1	3
3	2	3	2	3	2	3	2	3	2	3
3	1	2	1	2	1	2	1	2	1	3
3	3	3	3	3	3	3	3	3	3	3


Le 1 représente une couleur
Le 2 représente une autre couleur
Le 3 Représente des bloc non destructibles et impossible à traverser

Nécéssité d'avoir plusieurs couleurs pour différencier la position du joueur









									Menu en lui même

Composition du Menu : 

	-Un fond
	-Un ensemble de bouton
	-Une musique ? ( oui à trouver )