#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define MAX 100

int generaMatrice(int mat[][MAX], int dim)
{
    system("cls");
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            mat[i][j] = (rand() % 99) + 1;
        }
    }
}

int stampaMatricesuCSV(int mat[][MAX], int dim)
{
    system("cls");
    FILE *fp = fopen("matrice.csv", "w");
    if (fp == NULL)
    {
        printf("\nApertura file fallita");
        return 1;
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            fprintf(fp, "%d,", mat[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int stampaMatricedaCSV(int mat[][MAX], int dim)
{
    system("cls");
    char riga[100];
    char *valore;
    FILE *fp = fopen("matrice.csv", "r");
    if (fp == NULL)
    {
        printf("\nApertura file fallita");
        return 1;
    }

    int i = 0;
    while (fgets(riga, 100, fp))
    {
        valore = strtok(riga, ",");

        int j = 0;

        while (valore != NULL)
        {
            mat[i][j] = atoi(valore);
            valore = strtok(NULL, ",");
            j++;
        }
        i++;
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            printf("|");
            printf("\t%d\t", mat[i][j]);
            printf("|");
        }
        printf("\n\n");
    }

    fclose(fp);
}

int esciDalProgramma()
{
    system("cls");
    printf("Interruzione del programma...\n\n");
    exit(1);
}

int main(void)
{
    system("cls");
    int mat[MAX][MAX], dim, scelta;

    printf("\nInserire la dimensione della matrice: ");
    scanf("%d", &dim);
    printf("\n");

    while (scelta = !0)
    {
        printf("Operazioni disponibili:\n");
        printf("\n1 - Generare una matrice quadrata casuale di dimensione %d;\n", dim);
        printf("\n2 - Salvare la matrice sul file \"matrice.csv\";\n");
        printf("\n3 - Stampare a video la matrice dal file CSV;\n");
        printf("\n0 - Uscire dal programma.\n");

        do
        {
            printf("\nInserire l'operazione da eseguire: ");
            scanf("%d", &scelta);
        } while (scelta < 0 || scelta > 3);

        switch (scelta)
        {
        case 0:
            esciDalProgramma();
        case 1:
            generaMatrice(mat, dim);
            printf("\nOperazione di generazione matrice effettuata con successo!\n\n");
            break;
        case 2:
            stampaMatricesuCSV(mat, dim);
            printf("\nOperazione di salvataggio matrice su file CSV effettuata con successo!\n\n");
            break;
        case 3:
            stampaMatricedaCSV(mat, dim);
            printf("\nOperazione di stampa matrice a video da file CSV effettuata con successo!\n\n");
            break;
        }
    }
}