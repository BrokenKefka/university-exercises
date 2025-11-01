/*
Descrizione

Tesla desidera monitorare le vendite giornaliere dei suoi principali modelli:
Model S, Model 3, Model X e Model Y.

Obiettivo

Scrivere un programma in linguaggio C che registri le vendite giornaliere per ciascun modello durante una settimana, e calcoli le principali statistiche richieste.

Specifiche

Matrice delle vendite

Utilizzare una matrice di tipo int con 4 righe (una per ogni modello) e 7 colonne (una per ogni giorno della settimana).

Ogni elemento rappresenta il numero di auto vendute da un determinato modello in un determinato giorno.

Menu interattivo
Il programma deve permettere all’utente di scegliere una delle seguenti opzioni:

1) GENERARE: generare casualmente i dati di vendita (valori interi compresi tra 0 e 100).

2) CALCOLARE: calcolare le statistiche richieste.

3) STAMPARE: visualizzare i risultati.

0) TERMINARE: chiudere il programma.

Statistiche da calcolare

La media giornaliera delle vendite (somma delle vendite di tutti i modelli in un giorno, divisa per 4).

Il totale settimanale di ciascun modello (somma delle vendite giornaliere del modello).

Il modello con più vendite totali durante la settimana.

Stampa dei risultati

Visualizzare la matrice delle vendite (4×7).

Visualizzare l’array delle medie giornaliere (7 valori).

Visualizzare il nome del modello con il totale più alto di vendite.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MODELLO 4
#define GIORNO 7
#define MIN 0
#define MAX 100
#define SCELTA1 1
#define SCELTA2 2
#define SCELTA3 3
#define SCELTA0 0

int main() {
    //inizializzazione seed
    srand(time(NULL));

    int vendite[MODELLO][GIORNO], totvenditeSett[MODELLO]; //matrice vendite e array vendite modelli settimanali
    float medieSetiimana[GIORNO]; //media settimana
    float mediaGiornaliera, sommaGiornaliera; //variabile di appoggio
    int sommaModSet, venditeMAX = 0, numero, indexModello = 0;
    int scelta, i, j, count; //variabili di controllo
    i = 0;
    j = 0;
    sommaGiornaliera = 0;
    count = 0;
    sommaModSet = 0;

    do { // inizio esercizio 1
        // stampa del menù
        printf("\nDate le seguenti opzioni:\n");
        printf("1) Generazione dati.\n");
        printf("2) Calcolo statistiche richieste.\n");
        printf("3) Stampa dei risultati.\n");
        printf("0) Termina il programma.\n");
        printf("\n");
        printf("Scegli quale operazione vuoi effettuare:\n");
        scanf("%d", &scelta);

        switch (scelta) { //gestione scelte
            case SCELTA1:

                printf("Generazione della matrice...\n");

                //generazione matrice
                for (i = 0; i < MODELLO; i++) {
                    for (j = 0; j < GIORNO; j++) {
                        numero = MIN + rand() % (MAX - MIN + 1);
                        vendite[i][j] = numero;
                    }
                }
                break;

            case SCELTA2:

                printf("Svolgimenti calcoli...\n");

                // array contenente media di ogni giorno
                for (j = 0; j < GIORNO; j++) {
                    sommaGiornaliera = 0;
                    count = 0;
                    for (i = 0; i < MODELLO; i++) {
                        sommaGiornaliera += vendite[i][j];
                        count++;
                    }
                    mediaGiornaliera = sommaGiornaliera / (float) count;
                    medieSetiimana[j] = mediaGiornaliera;
                }

                //array con le vendite totali di ogni modello durante la settimana
                for (i = 0; i < MODELLO; i++) {
                    sommaModSet = 0;
                    for (j = 0; j < GIORNO; j++) {
                        sommaModSet += vendite[i][j];
                    }
                    totvenditeSett[i] = sommaModSet;
                }

                //modello che ha venduto di più
                indexModello = 0;
                venditeMAX = 0;
                for (i = 0; i < MODELLO; i++) {
                    if (totvenditeSett[i] > venditeMAX) {
                        venditeMAX = totvenditeSett[i];
                        indexModello = i;
                    }
                }
                break;

            case SCELTA3:

                printf("\nStampa matrice vendite.\n");

                //stampa matrice vendite
                for (i = 0; i < MODELLO; i++) {
                    for (j = 0; j < GIORNO; j++) {
                        printf(" %5d ", vendite[i][j]);
                    }
                    printf("\n");
                }

                printf("\nStampa media giornaliera vendite.\n");

                //stampa media giornaliera delle vendite
                for (j = 0; j < GIORNO; j++) {
                    printf("Media settimanale giorno %d: %5.2f\n", j, medieSetiimana[j]);
                }

                printf("\nStampa totale vendite settimanali di ogni modello.\n");

                //stampa vendite modelli settimanale
                for (i = 0; i < MODELLO; i++) {
                    printf("Totale settimanale modello %d: %d\n", i, totvenditeSett[i]);
                }

                //stampa modello che ha venduto di più nella settimana
                printf("Modello che ha venduto di più durante la settimana: %d\n", indexModello);

                break;

            case SCELTA0:
                //termine programma
                printf("Terminazione del programma.\n");
                break;

            default: //gestione casi non validi
                printf("Scelta inserita non valida!\n");
        }
    } while (scelta != 0); //fine esercizio 1

    return 0; // exit point
}
