#include <MLV/MLV_all.h>
#include <stdio.h>
#include<stdbool.h>

/** Groupe TP4
 * Prashath Sivayanama
 * Thiruvanandarajah Kishor */

# define TAILLE_PLATEAU 7
# define TAILLE_MAX_NOM 20
# define TAILLE_CASE 75

typedef struct {
    char nom[TAILLE_MAX_NOM] ;
    char symbol ;
    int score ;
} Joueur ;


typedef struct {
    char plateau [TAILLE_PLATEAU + 2 ] [TAILLE_PLATEAU + 2 ] ;
    Joueur * joueurs [ 2 ] ;
} Plateau ;


/**
 * \brief Cette fonction nous permet de crée une liste de sous liste (plateau)  qui va nous aide à gerer le plateau de jeu et notammament la gestion des pion et de leur action (il y a 2 plateau un pour le mode ASII et l'autre pour le graphique  ).
 *
 * \param plat Pointeur vers structure
 * \param graphique Integer
 */
void PLATEAU(Plateau * plat ,int graphique){
    int i,j;
    /*plateau pour le ASCII*/
    printf("\n");
    if (graphique == 0){
        for (i=0;i<TAILLE_PLATEAU+2;i++){
            for (j=0;j<=TAILLE_PLATEAU+2;j++){
                if ((i==1 && j==1) || (i==TAILLE_PLATEAU && j==TAILLE_PLATEAU))
                {
                    plat->plateau[i][j] = 'x';
                }
                else if ((i==1 && j==TAILLE_PLATEAU) || (i==TAILLE_PLATEAU && j==1))
                {
                    plat->plateau[i][j] = 'o';
                }

                else if (i ==0 || i == TAILLE_PLATEAU+1)
                {
                    plat->plateau[i][j]= '*';
                }
                else if (i!=0 && i!= TAILLE_PLATEAU+1){
                    if (j==0|| j == TAILLE_PLATEAU+1)
                    {
                    plat->plateau[i][j]= '*';
                    }
                    if (j!=0 && j != TAILLE_PLATEAU+1)
                    {
                    plat->plateau[i][j]= '.';
                    }
                }

            }
        }
        }
    /*plateau pour le graphique */
    if (graphique == 1){
        for (i=0;i<TAILLE_PLATEAU;i++){
            for (j=0;j<TAILLE_PLATEAU;j++){
                plat->plateau[i][j] = '.';
                if ((i==0 && j==0) || (i==TAILLE_PLATEAU-1 && j==TAILLE_PLATEAU-1))
                {
                    plat->plateau[i][j] = 'x';
                }
                else if ((i==0 && j==TAILLE_PLATEAU-1) || (i==TAILLE_PLATEAU-1 && j==0))
                {
                    plat->plateau[i][j] = 'o';
                }


            }
            
        }
        

    }
    
}

/**
 * \brief On initialise les nom,scores,symbole des différents joueurs .
 *
 * \param nom_j Pointeur vers structure
 */

void CHOIX_JOUEUR(Plateau *nom_j ){
    printf("Quel est le nom du premier joueur (symbol o) : ");
    scanf("%s",nom_j->joueurs[0]->nom);
    nom_j->joueurs[0]->symbol = 'o';
    nom_j->joueurs[0]->score = 2;
    printf("Quel est le nom du second joueur (symbol x) :");
    scanf("%s",nom_j->joueurs[1]->nom);
    nom_j->joueurs[1]->symbol = 'x';
    nom_j->joueurs[1]->score = 2;


}


/**
 * \brief On affiche le plateau de jeu  .
 *
 * \param plat variable de structure
 */
void affichage_plateau(Plateau plat){
    int l,k;
    for ( l = 0; l < TAILLE_PLATEAU+2; l++)
    {
        for ( k = 0; k < TAILLE_PLATEAU+2; k++)
        {
            printf("%c ",plat.plateau[l][k]);
        }
        printf("\n");
        
    } 
    
}
/**
 * \brief on vérifie que il y a encore des case vide .
 *
 * \param Joueur Pointeur vers structure
 * \param type integer
 * \return false,true(boolean)
 */
bool verifie_la_possibilite_de_jouer(Plateau *Joueur,int type ){
    int compteur_de_place_1,compteur_de_place_2;
    if (type == 0)/*ASCII*/
    {
       for (compteur_de_place_1=0;compteur_de_place_1<TAILLE_PLATEAU+2;compteur_de_place_1++){
        for (compteur_de_place_2=0;compteur_de_place_2<=TAILLE_PLATEAU+2;compteur_de_place_2++){
            if (Joueur->plateau[compteur_de_place_1][compteur_de_place_2] == '.')
            {
                return true;

            }
        }
    }
    return false;
    }
    if (type == 1)/*graphique*/
    {
        for (compteur_de_place_1=0;compteur_de_place_1<TAILLE_PLATEAU;compteur_de_place_1++){
        for (compteur_de_place_2=0;compteur_de_place_2<TAILLE_PLATEAU;compteur_de_place_2++){
            if (Joueur->plateau[compteur_de_place_1][compteur_de_place_2] == '.')
            {
                return true;

            }
        }
    }
    }
    return false;
    
}
   /**
 * \brief Fonction qui gere la victoire des joueur 
 *
 * \param joueur Pointeur vers structure
 * \return 1,2,3,0 (integer)
 */         

int condition_de_victoire(Plateau *Joueur , int type ){
    
    if (Joueur->joueurs[0]->score == 0 )/*le joueur 1 a perdu*/
    {
        return 1 ;
    }
    if (Joueur->joueurs[1]->score == 0)/*le joueur  2 a perdu*/
    {
        return 2 ;
    }
    if (verifie_la_possibilite_de_jouer(Joueur,type) == false)/*Nous n'avons plus de case libre */
    {
        return 3;
    }
    
    return 0;
    
    
}
 /**
 * \brief On calcule les scores des deux joueurs et en cas de victoire cette fonction affiche le vainqueur (affichage ASCII et GRAPHIQUE) par rapport aux score de chacun  .
 *
 * \param Joueur Pointeur vers structure
 * \param plat variable de structure
 * \param type integer
 */
void score(Plateau plat ,Plateau * Joueur,int type){
    int l,k ;
    Joueur->joueurs[0]->score = 0;
    Joueur->joueurs[1]->score = 0;
    if (type == 0) { /*ascii*/
        for ( l = 0; l < TAILLE_PLATEAU+2; l++)
        {
            for ( k = 0; k < TAILLE_PLATEAU+2; k++)
            {
                if (plat.plateau[l][k] == Joueur->joueurs[0]->symbol)
                {
                    Joueur->joueurs[0]->score += 1;
                }
                if (plat.plateau[l][k] == Joueur->joueurs[1]->symbol)
                {
                    Joueur->joueurs[1]->score += 1;
                }            

            }    
        }
    }
    if (type == 1)/*graphique*/
    {
        for ( l = 0; l < TAILLE_PLATEAU; l++)
        {
            for ( k = 0; k < TAILLE_PLATEAU; k++)
            {
                if (plat.plateau[l][k] == Joueur->joueurs[0]->symbol)
                {
                    Joueur->joueurs[0]->score += 1;
                }
                if (plat.plateau[l][k] == Joueur->joueurs[1]->symbol)
                {
                    Joueur->joueurs[1]->score += 1;
                }            

            }    
        }
    }
    
    switch (condition_de_victoire(Joueur,type))
    {
    case 0:
        printf("Score actuel : %s(%c) %d - %s(%c) %d \n",Joueur->joueurs[0]->nom,Joueur->joueurs[0]->symbol,Joueur->joueurs[0]->score,Joueur->joueurs[1]->nom,Joueur->joueurs[1]->symbol,Joueur->joueurs[1]->score);
        break;
    case 1:
        printf("Bravo %s , vous avez gagné %d à %d .\n",Joueur->joueurs[1]->nom,Joueur->joueurs[1]->score,Joueur->joueurs[0]->score);
        if (type == 1){
            MLV_clear_window(MLV_COLOR_BLACK);
            MLV_draw_text(((TAILLE_PLATEAU*100)/2)-50,((TAILLE_PLATEAU*100)/2)-50,"Bravo joueur 2 vous avez gagné ", MLV_COLOR_WHITE);
            MLV_actualise_window();
            MLV_wait_seconds(20);
            MLV_free_window();
        }
        break;
    case 2:
        printf("Bravo %s , vous avez gagné %d à %d . \n",Joueur->joueurs[0]->nom,Joueur->joueurs[0]->score,Joueur->joueurs[1]->score);
        if (type == 1){
            MLV_clear_window(MLV_COLOR_BLACK);
            MLV_draw_text(((TAILLE_PLATEAU*100)/2)-50,((TAILLE_PLATEAU*100)/2)-50 ,"Bravo joueur 1 vous avez gagné ", MLV_COLOR_WHITE);
            MLV_actualise_window();
            MLV_wait_seconds(30);
            MLV_free_window();
        }
        break;
    case 3:
        if ( Joueur->joueurs[0]->score > Joueur->joueurs[1]->score)
            {
                printf("Bravo %s , vous avez gagné %d à %d .\n",Joueur->joueurs[0]->nom,Joueur->joueurs[0]->score,Joueur->joueurs[1]->score);
                if (type == 1){
                MLV_clear_window(MLV_COLOR_BLACK);
                MLV_draw_text(((TAILLE_PLATEAU*100)/2)-50,((TAILLE_PLATEAU*100)/2)-50,"Bravo joueur 1 vous avez gagné ", MLV_COLOR_WHITE);
                MLV_actualise_window();
                MLV_wait_seconds(30);
                MLV_free_window();}
             
            }
        if (Joueur->joueurs[1]->score > Joueur->joueurs[0]->score)
            {
                printf("Bravo %s , vous avez gagné %d à %d .\n",Joueur->joueurs[1]->nom,Joueur->joueurs[1]->score,Joueur->joueurs[0]->score);
                if (type == 1){
                MLV_clear_window(MLV_COLOR_BLACK);
                MLV_draw_text(((TAILLE_PLATEAU*100)/2)-50,((TAILLE_PLATEAU*100)/2)-50 ,"Bravo joueur 2 vous avez gagné ", MLV_COLOR_WHITE);
                MLV_actualise_window();
                MLV_wait_seconds(30);
                MLV_free_window();}
            }
        
        if (Joueur->joueurs[1]->score == Joueur->joueurs[0]->score)
        {
            printf("Egalité %d à %d .\n", Joueur->joueurs[1]->score,Joueur->joueurs[0]->score);
            if (type == 1){
            MLV_clear_window(MLV_COLOR_BLACK);
            MLV_draw_text(((TAILLE_PLATEAU*100)/2)-50,((TAILLE_PLATEAU*100)/2)-50," Egalité", MLV_COLOR_WHITE);
            MLV_actualise_window();
            MLV_wait_seconds(30);
            MLV_free_window();}
        }
        break;
    
    default:
        break;
    }
    
    
}
/**
 * \brief Cette fonction permet de vérifier si il y' a des pions adverse aux alentour de l'emplacement(8 case aux alentour) voulut et de les convertir au symbole du joueur actif.
 *
 * \param pion_alentour Pointeur vers structure
 * \param x integer
 * \param y integer 
 * \param symbol char
 * \param joueur_adverse char 
 * \return  true false (boolean)
 * \return choix (integer)
 */
bool changement_des_pion_aux_alentour(Plateau * pion_alentour, int x,int y,char symbol,char joueur_adverse){
    int choix = 0;
    if (pion_alentour->plateau[y][x+1]== joueur_adverse)/* droite*/
    {   
        pion_alentour->plateau[y][x+1] = symbol;
        choix+=1;
    }
    if (pion_alentour->plateau[y][x-1]== joueur_adverse)/* gauche*/
    {
        pion_alentour->plateau[y][x-1] = symbol;
        choix+=1;
    }
    if (pion_alentour->plateau[y-1][x]== joueur_adverse)/* haut*/
    {
        pion_alentour->plateau[y-1][x] = symbol;
        choix+=1;
    }
    if (pion_alentour->plateau[y+1][x]== joueur_adverse)/* bas*/
    {
        pion_alentour->plateau[y+1][x] = symbol;
        choix+=1;
    }
    if (pion_alentour->plateau[y-1][x+1]== joueur_adverse)/* droite-haut*/
    {
        pion_alentour->plateau[y-1][x+1] = symbol;
        choix+=1;
    }
    if (pion_alentour->plateau[y+1][x+1]== joueur_adverse)/* droite-bas*/
    {
        pion_alentour->plateau[y+1][x+1] = symbol;
        choix+=1;
    }
    if (pion_alentour->plateau[y-1][x-1]== joueur_adverse)/* gauche-haut*/
    {
        pion_alentour->plateau[y-1][x-1] = symbol;
        choix+=1;
    }
    if (pion_alentour->plateau[y+1][x-1]== joueur_adverse)/* gauche-bas*/
    {
        pion_alentour->plateau[y+1][x-1] = symbol;
        choix+=1;
    }
    if (choix != 0 ){
        return true;
    }
    return false;
    
}

/**
 * \brief   On vérifie les coordonées saisi du joueur et si c'est vérifié on va poser son pion et on va convertir les pions adverses aux alentour.
 *
 * \param pion Pointeur vers structure
 * \param tour integer
 */
void coordonnee_pion_verifie(Plateau *pion,int tour){
    if (tour == 0)
    {   int x, y;
        do
        {
            printf("%s (%c), veuillez saisir les coordonnées ou jouer (entre 1 et %d) : ",pion->joueurs[0]->nom,pion->joueurs[0]->symbol,TAILLE_PLATEAU);
            scanf("%d %d",&y,&x);
        } while (pion->plateau[y][x]== '*' || pion->plateau[y][x] == pion->joueurs[1]->symbol || changement_des_pion_aux_alentour(pion,x,y,pion->joueurs[0]->symbol,pion->joueurs[1]->symbol)==false);/* revoie true dés que c'est pas un bon emplacement pour poser le pion .*/
        pion->plateau[y][x] = pion->joueurs[0]->symbol;
        changement_des_pion_aux_alentour(pion,x,y,pion->joueurs[0]->symbol,pion->joueurs[1]->symbol);

    }
    if (tour == 1)
    {   int x, y;
        do
        {
            printf("%s (%c), veuillez saisir les coordonnées ou jouer (entre 1 et %d) : ",pion->joueurs[1]->nom,pion->joueurs[1]->symbol,TAILLE_PLATEAU);
            scanf("%d %d",&y,&x);

        } while ((pion->plateau[y][x]== '*' || pion->plateau[y][x] == pion->joueurs[0]->symbol)||changement_des_pion_aux_alentour(pion,x,y,pion->joueurs[1]->symbol,pion->joueurs[0]->symbol) == false);
        pion->plateau[y][x] = pion->joueurs[1]->symbol;
        changement_des_pion_aux_alentour(pion,x,y,pion->joueurs[1]->symbol,pion->joueurs[0]->symbol);

    }
    
    
}


/**
 * \brief   On affiche le plateau graphiquement avec les pions .
 *
 * \param liste_plateau Pointeur vers structure
 * \param tour integer
 */

void plateau_graphique(Plateau*liste_plateau,int tour){
    for (int colonne = 0; colonne < TAILLE_PLATEAU; colonne++)
    {
        for (int ligne = 0; ligne < TAILLE_PLATEAU; ligne ++)
        {
            MLV_draw_rectangle(colonne * TAILLE_CASE ,ligne* TAILLE_CASE,TAILLE_CASE,TAILLE_CASE,MLV_COLOR_GOLDENROD4);
            if (liste_plateau ->plateau[colonne][ligne]== liste_plateau->joueurs[0]->symbol)
            {
                MLV_draw_filled_circle((ligne *TAILLE_CASE)+TAILLE_CASE/2,(colonne *TAILLE_CASE)+TAILLE_CASE/2, TAILLE_CASE/2, MLV_COLOR_INDIAN_RED);
            }
            if (liste_plateau ->plateau[colonne][ligne]== liste_plateau->joueurs[1]->symbol)
            {   
                MLV_draw_filled_circle((ligne *TAILLE_CASE)+TAILLE_CASE/2,(colonne *TAILLE_CASE)+TAILLE_CASE/2, TAILLE_CASE/2, MLV_COLOR_SEA_GREEN);
            }
            
            
        }
        
    }
    if (tour == 0){
        MLV_draw_text( (TAILLE_CASE*TAILLE_PLATEAU)/8,(TAILLE_CASE*TAILLE_PLATEAU)+50,"A vous de jouer :", MLV_COLOR_WHITE);
        MLV_draw_text( (TAILLE_CASE*TAILLE_PLATEAU)/2,(TAILLE_CASE*TAILLE_PLATEAU)+50 ,liste_plateau->joueurs[0]->nom, MLV_COLOR_INDIAN_RED);
    }
    if (tour == 1){
        MLV_draw_text( (TAILLE_CASE*TAILLE_PLATEAU)/8,(TAILLE_CASE*TAILLE_PLATEAU)+50 ,"A vous de jouer :", MLV_COLOR_WHITE);
        MLV_draw_text( (TAILLE_CASE*TAILLE_PLATEAU)/2,(TAILLE_CASE*TAILLE_PLATEAU)+50, liste_plateau->joueurs[1]->nom, MLV_COLOR_SEA_GREEN);
    }


    
}

/**
 * \brief   On vérifie les clique du joueur si il a cliqué sur une case libre et entouré de pion adverse .
 *
 * \param tab Pointeur vers structure
 * \param x integer
 * \param y integer
 * \param  symbole_du_joueur_active char
 * \param  symbole_du_joueur_adverse char
 * \return false,true (boolean)
 */
bool verification_du_clic(Plateau * tab,int x,int y, char symbole_du_joueur_active ,char symbole_du_joueur_adverse ){
    if ((0<= x)&&(x<= TAILLE_PLATEAU -1) && (0<= y)&&(y<= TAILLE_PLATEAU -1))/*vérification que les nombre soit dans le rectangle*/
    { 
        if (tab->plateau[y][x] == '.' && changement_des_pion_aux_alentour(tab,x,y,symbole_du_joueur_active,symbole_du_joueur_adverse)){/**vérification que il n' ait  pas cliqué sur un pion déja active */
        return true ;
        }
        return false;
    }
    return false;


}

/**
 * \brief   Fonction qui va gérer le clique et la vérification et la contamination des pions adverses par rapport aux joueur actif  .
 *
 * \param player Pointeur vers structure
 * \param tour_du_joueur integer
 * \param  symbole char
 * \param  symbole_adverse char
 */
void clique (Plateau*player,int tour_du_joueur,char symbole,char symbole_adverse){
    int x,y ,nv_x,nv_y;
    
    if (tour_du_joueur ==0 ){/*clique du joueur 1*/
        do{
            MLV_wait_mouse(&x,&y);
            nv_x= x/TAILLE_CASE;
            nv_y = y/TAILLE_CASE;}
        while (verification_du_clic(player,nv_x,nv_y,symbole,symbole_adverse)!= true);
        player->plateau[nv_y][nv_x] = player->joueurs[0]->symbol;
        changement_des_pion_aux_alentour(player, nv_x,nv_y,player->joueurs[0]->symbol,player->joueurs[1]->symbol);
    }   
    if (tour_du_joueur == 1 ){/*clique du joueur 2*/
        do{
            MLV_wait_mouse(&x,&y);
            nv_x= x/TAILLE_CASE;
            nv_y = y/TAILLE_CASE;}
        while (verification_du_clic(player,nv_x,nv_y,symbole,symbole_adverse)!= true);
        player->plateau[nv_y][nv_x] = player->joueurs[1]->symbol;
        changement_des_pion_aux_alentour(player, nv_x,nv_y,player->joueurs[1]->symbol,player->joueurs[0]->symbol);
    }   
   
}
/**
 * \brief  Cette fonction relie le clique du joueur et l'affichage graphique du plateau   .
 *
 * \param jeu_affichage Pointeur vers structure
 * \param tour integer
 * \param nom_joueur integer
 * \param  symbole_active char
 * \param  symbole_adverse char
 */
void affichage_graphique(Plateau *jeu_affichage,int tour,int nom_joueur,char symbole_active,char symbole_adverse){
    clique(jeu_affichage,tour,symbole_active,symbole_adverse);
    MLV_clear_window(MLV_COLOR_BLACK);
    plateau_graphique(jeu_affichage,nom_joueur),
    MLV_actualise_window();

}
    
int main(int argc , char * argv[]){
    Plateau plat ;
    Joueur Joueur_1 ,Joueur_2;
    plat.joueurs[0]= & Joueur_1;
    plat.joueurs[1] = & Joueur_2;

    if( strcmp( argv[2], "-h") == 0 && strcmp( argv[1], "-a") == 0){/*ASCII POUR 2 JOUEUR */
        int type_plateau = 0, tour = 0;
        CHOIX_JOUEUR(&plat);
        PLATEAU(&plat,type_plateau);
        affichage_plateau(plat);

        while ( condition_de_victoire(&plat,type_plateau)==0)
        {
            if (tour == 0 && condition_de_victoire(&plat,type_plateau)==0 ) /*Tour du premier joueur */
            {
                coordonnee_pion_verifie(&plat,tour);
                affichage_plateau(plat);
                score(plat,&plat,type_plateau);
                tour +=1;

            }
            if (tour == 1 && condition_de_victoire(&plat,type_plateau)==0)/*Tour du deuxième joueur */
            {
                coordonnee_pion_verifie(&plat,tour);
                affichage_plateau(plat);
                score(plat,&plat,type_plateau);
                tour -=1;
            }
        } 
    }
    if (strcmp( argv[1], "-g") == 0 && strcmp( argv[2], "-h") == 0 ){
        int type_plateau = 1, tour = 0;
        CHOIX_JOUEUR(&plat);
        PLATEAU(&plat,type_plateau);
        MLV_create_window("DM","ATTAX",TAILLE_PLATEAU*100,TAILLE_PLATEAU*100);
        plateau_graphique(&plat,0);
        MLV_actualise_window();
        while ( condition_de_victoire(&plat,type_plateau)==0){
            if (tour == 0 && condition_de_victoire(&plat,type_plateau)==0 ){/*Tour du premier joueur */
                affichage_graphique(& plat ,tour,1,plat.joueurs[0]->symbol,plat.joueurs[1]->symbol);
                score(plat,&plat,type_plateau);
                tour +=1;
            }
            if (tour == 1 && condition_de_victoire(&plat,type_plateau)==0){/*Tour du deuxième joueur */
                affichage_graphique(& plat,tour,0,plat.joueurs[1]->symbol,plat.joueurs[0]->symbol);
                score(plat,&plat,type_plateau);
                tour -=1;
            }
        }
    }
    return 0;
}