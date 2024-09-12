#include <stdio.h>
#include <string.h>

typedef struct
{
    int numero;
    char nom[50];
    char prenom[50];
    char date_naissance[10];
    char departement[50];
    float note_general;
} Etudiant;

Etudiant max_etudiants[100];
int nombre_etudiant = 0;
void ajoutetudiant()
{

    printf("Entrez numero unique : ");
    scanf("%d", &max_etudiants[nombre_etudiant].numero);
    printf("Entrez nom : ");
    scanf("%s", max_etudiants[nombre_etudiant].nom);
    printf("Entrez prenom : ");
    scanf("%s", max_etudiants[nombre_etudiant].prenom);
    printf("Entrez date naissance (JJ/MM/AAAA) : ");
    scanf("%s", max_etudiants[nombre_etudiant].date_naissance);
    printf("Entrez departement : ");
    scanf("%s", max_etudiants[nombre_etudiant].departement);
    printf("Entrez la note general : ");
    scanf("%f", &max_etudiants[nombre_etudiant].note_general);
    nombre_etudiant++;
}

void Modifieretudiant()
{
    int numero;
    printf("Entrez le nombre d'etudiant: ");
    scanf("%d", &numero);
    for (int i = 0; i < nombre_etudiant; i++)
    {
        if (max_etudiants[i].numero == numero)
        {
            printf("Modifier les informations d'etudiant %d:\n", numero);
            printf("Nom : ");
            scanf("%s", max_etudiants[i].nom);
            printf("Prenom : ");
            scanf("%s", max_etudiants[i].prenom);
            printf("Date de naissance (JJ/MM/AAAA) : ");
            scanf("%s", max_etudiants[i].date_naissance);
            printf("Departement : ");
            scanf("%s", max_etudiants[i].departement);
            printf("Note generale : ");
            scanf("%f", &max_etudiants[i].note_general);
            return;
        }
    }
    printf("Etudiant non trouve!\n");
}
void supprimetudiant()
{
    int numero;
    printf("Entrez le nemero d'etudiant : \n");
    scanf("%d", &numero);
    for (int i = 0; i < nombre_etudiant; i++)
    {
        if (max_etudiants[i].numero == numero)
        {
            for (int j = i; j < nombre_etudiant - 1; j++)
            {
                max_etudiants[j] = max_etudiants[j + 1];
            }
            nombre_etudiant--;
            printf("Etudiant a ete supprime.\n");
            return;
        }
    }
    printf("Etudiant non trouve!\n");
}
void affiche_detaile_E()
{
    int numero;
    printf("Entrez numero d'etudiant: ");
    scanf("%d", &numero);
    for (int i = 0; i < nombre_etudiant; i++)
    {
        if (max_etudiants[i].numero == numero)
        {
            printf("Numero d'etudiant: %d\n", max_etudiants[i].numero);
            printf("Nom d'etudiant: %s\n", max_etudiants[i].nom);
            printf("Prenom d'etudiant: %s\n", max_etudiants[i].prenom);
            printf("Date naissance d'etudiant: %s\n", max_etudiants[i].date_naissance);
            printf("Departement d'etudiant: %s\n", max_etudiants[i].departement);
            printf("Note generale d'etudiant: %.2f\n", max_etudiants[i].note_general);
            return;
        }
    }
    printf("Etudiant non trouve!\n");
}
void calculer_moyenne_generale()
{
    float moyenne;
    float somme;
    somme = 0;
    for (int i = 0; i < nombre_etudiant; i++)
    {
        somme += max_etudiants[i].note_general;
    }
    moyenne = somme / nombre_etudiant;
    printf("Moyenne general etudian est: %.2f\n", moyenne);
}
void Affiche_Nombre_Total_Etudiant()
{
    printf(" Le nombre total d'etudiants inscrits est: %d\n", nombre_etudiant);
}
void Recherche_Etudiant_Nom()
{
    char nom_rech[50];
    printf("Entrez le nom de l'etudiant recherche");
    scanf("%s", nom_rech);
    for (int i = 0; i < nombre_etudiant; i++)
    {
        if (strcmp(max_etudiants[i].nom, nom_rech) == 0)
        {
            printf("Nombre etudiant: %d\n", max_etudiants[i].numero);
            printf("Nom etudiant: %s\n", max_etudiants[i].nom);
            printf("Prenom etudiant: %s\n", max_etudiants[i].prenom);
            printf("Date naissance etudiant: %s\n", max_etudiants[i].date_naissance);
            printf("Departement etudiant: %s\n", max_etudiants[i].departement);
            printf("Note generale etudiant: %.2f\n", max_etudiants[i].note_general);
        }
        else
            printf("Etudiant non trouve!\n");
    }
}

int main()
{

    int choix;

    while (choix != 9)
    {
        printf("--------Menu-------- \n");
        printf("--------------------\n");
        printf("1-Ajoute un etudiant\n");
        printf("2-Modifier un etudiant\n");
        printf("3-Supprimer un etudiant\n");
        printf("4-Afficher les details d'un etudiant\n");
        printf("5-Calculer la moyenne generale \n");
        printf("6-Afficher le nombre total d'etudiants inscrits\n");
        printf("7-Rechercher un etudiant par nom\n");
        printf("8-Quitter\n");
        printf("Entrez votre choix :");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            ajoutetudiant();
            break;
        case 2:
            Modifieretudiant();
            break;
        case 3:
            supprimetudiant();
            break;
        case 4:
            affiche_detaile_E();
            break;
        case 5:
            calculer_moyenne_generale();
            break;
        case 6:
            Affiche_Nombre_Total_Etudiant();
            break;
        case 7:
            Recherche_Etudiant_Nom();
            break;
        case 8:
            return 0;
        default:
            printf("Choix non valide!");
        }
    }

    return 0;
}
