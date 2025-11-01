/**
 * NOME			Giuseppe
 * COGNOME:     D'Alessandro
 * MATRICOLA:   60/84/0075
 */

/** === DESCRIZIONE ====================================================================================================
 * CONTESTO: Il Prof. Loddo vuole un programma che monitori i voti degli studenti negli esami del primo semestre:
 * Programmazione 1 Modulo 1, Programmazione 1 Modulo 2, Analisi e Fondamenti di Informatica.
 *
 * OBIETTIVO: Scrivere un’applicazione in C che registri i voti degli studenti e poi calcoli alcune statistiche sui risultati.
 *
 * SVOLGIMENTO: Il lavoro è diviso in tre parti:
 * 1.  Creare un menu per far scegliere all’utente cosa fare (ESERCIZIO 1).
 * 2.  Gestione e manipolazione dei dati attraverso matrici/array (ESERCIZI 2, 3).
 * 3.  Stampare a schermo i risultati ottenuti (ESERCIZIO 4).
 *
 * CONSIGLI: Risolvere gli esercizi in ordine di numerazione, ma non rimanere bloccati su un esercizio troppo a lungo.
 * L’ordine crescente degli esercizi non rappresenta una difficoltà crescente.
 *
 * VALUTAZIONE: Gli esercizi hanno un punteggio. Se svolti tutti correttamente si raggiunge il 25. I rimanenti
 * 5 punti valutano i seguenti aspetti: stile e organizzazione del codice, uso delle best practice, commenti.
 *
 * NOTA BENE: È severamente vietato modificare il codice fornito.
 */

/** Inclusioni librerie docente */
#include <stdio.h>
/** Fine inclusioni librerie docente */

/** Inclusioni librerie studente */
#include <stdlib.h>
#include <time.h>
/** Fine inclusioni librerie studente */

/** Macro studente */
#define SCELTA_1 1
#define SCELTA_2 2
#define SCELTA_3 3
#define SCELTA_0 0
#define STUDENTI 4
#define ESAMI 4
#define MIN_VOTO 0
#define MAX_VOTO 3000
#define COEFF 100.00
#define SUFFICIENZA 18
/** Fine macro studente */

int main(void) {
    srand(time(NULL));
    /** Variabili studente */
    float votiStudenti[STUDENTI][ESAMI]; //matrice 4x4
    float mediaStudenti[STUDENTI]; //array media voti di ogni studente
    float mediaEsami[ESAMI]; //array media voti di ogni esame
    float voto, sommaEs, mediaEs, sommaSt, mediaSt; //somma voti per esami e studenti con relativa media
    int scelta, i, j, count; //variabili di controllo
    i = 0;
    j = 0;
    count = 0;
    sommaEs = 0;
    /** Fine variabili studente */

    /* === ESERCIZIO 1 (MENU) ================================================================================
     * Realizzare un menu che, ciclicamente, permetta di scegliere tra le seguenti opzioni:
     * TASTO 1) INSERIRE/GENERARE (ESERCIZIO 2);
     * TASTO 2) CALCOLARE (ESERCIZIO 3);
     * TASTO 3) STAMPARE (ESERCIZIO 4);
     * TASTO 0) TERMINARE.
     */
    do { // inizio esercizio 1
        printf("\nDate le seguenti opzioni:\n");
        printf("TASTO 1) INSERIRE/GENERARE (ESERCIZIO 2)\n");
        printf("TASTO 2) CALCOLARE (ESERCIZIO 3)\n");
        printf("TASTO 3) STAMPARE (ESERCIZIO 4)\n");
        printf("TASTO 0) TERMINARE.\n");
        printf("Scegli quale opzioni effettuare:\n");
        scanf("%d", &scelta);

        switch (scelta) { //gestione scelte
        /* === ESERCIZIO 2 (GENERAZIONE) ================================================================================
         * Una matrice float 4x4 rappresenta i voti di 4 studenti (righe) nei 4 esami del primo semestre (colonne).
         * Generare casualmente i voti nella matrice come float con due decimali utili, considerando che:
         * - i voti sono compresi tra 0.0 e 30.0 (estremi inclusi);
         * - i voti < 18.0 rappresentano esami non superati e vanno salvati come 0.0 nella matrice;
         *
         * ESEMPIO DI MATRICE GENERATA:
         * (Ogni riga rappresenta uno studente, ogni colonna un esame)
         *			  PR1M1   PR1M2   AM      FDI
         * Studente1  28.2    30.0    26.1    27.5
         * Studente2  22.3    24.5    25.7    27.3
         * Studente3  30.0    29.5    30.8    28.5
         * Studente4  19.5    20.2    22.9    24.5
         */
            case SCELTA_1: //esercizio 2

                printf("Generazione della matrice...\n");

                // generazione matrice
                for (i = 1; i <= STUDENTI; i++) {
                    for (j = 1; j <= ESAMI; j++) {
                        voto = (MIN_VOTO + rand() % (MAX_VOTO - MIN_VOTO + 1)) / COEFF;
                        if (voto < SUFFICIENZA) { //voto inferiore a 18 non valido inserito come 0
                            votiStudenti[i][j] = 0;
                        } else {
                            votiStudenti[i][j] = voto;
                        }
                        //printf(" %.2f ", votiStudenti[i][j]);
                    }
                    //printf("\n");
                }
                break; //fine esercizio 2


                /* === ESERCIZIO 3 (STATISTICHE) ================================================================================
                 * Un array float di 4 elementi rappresenta le medie dei voti per ogni esame.
                 * Un array float di 4 elementi rappresenta le medie dei voti di ogni studente.
                 * Calcolare i due array a partire dalla matrice dei voti generata nell’esercizio 2.
                 */
            case SCELTA_2: //esercizio 3

                printf("Svolgimento calcoli...\n");

                for (j = 1; j <= ESAMI; j++) { //ripeto ciclo interno per ogni colonna
                    sommaEs = 0;
                    count = 0;
                    for (i = 1; i <= STUDENTI; i++) {
                        sommaEs += votiStudenti[i][j]; //sommo voti di ogni colonna
                        count++;
                    }
                    mediaEs = sommaEs / (float)count; // calcolo media di ogni colonna
                    mediaEsami[j] = mediaEs; // salvataggio in matrice
                    //printf("cella %d =  %.2f",j, mediaEsami[j]);
                    //printf("\n");
                }

                //printf("\n");

                for (i = 1; i <= STUDENTI; i++) { //ripeto ciclo interno per ogni riga
                    sommaSt = 0;
                    count = 0;
                    for (j = 1; j <= ESAMI; j++) {
                        sommaSt += votiStudenti[i][j]; //somma voto ogni riga
                        count++;
                    }
                    mediaSt = sommaSt / (float)count; // media voti ogni riga
                    mediaStudenti[i] = mediaSt; //salvataggio in matrice
                    //printf("cella %d =  %.2f",i, mediaStudenti[i]);
                    //printf("\n");
                }
                break; // fine esercizio 3
                /* === ESERCIZIO 4 (STAMPA) ================================================================================
                 * Stampare la matrice dei voti, l’array delle medie per esame e l’array delle medie per studente.
                 *
                 * Esempio:
                 * Stampa matrice voti
                 * 28.2 30.0 26.1 27.5
                 * 22.3 24.5 25.7 27.3
                 * 30.0 29.5 30.8 28.5
                 * 19.5 20.2 22.9 24.5
                 *
                 * Media dei voti per studente:
                 * 27.95 24.95 29.70 21.78
                 *
                 * Media dei voti per esame:
                 * 25.00 26.05 26.38 26.95
                 */
            case SCELTA_3: // inizio esercizio 4

                printf("\nVoti studenti. \n");

                //stampa matrice voti
                for (i = 1; i <= STUDENTI; i++) { //scorro righe (esami)
                    for (j = 1; j <= ESAMI; j++) { //scorro colonne (studenti)
                        printf(" %5.2f ", votiStudenti[i][j]);
                    }
                    printf("\n"); // alla fine di ogni riga vai a capo
                }

                printf("\nMedia voti studenti. \n"); // stampa array con media voti studenti
                for (i = 1; i <= STUDENTI; i++) {
                    printf("Studente %d: %.2f \n", i, mediaStudenti[i]);
                }

                printf("\nMedia voti esami. \n"); // stampa array con media voti esami
                for (j = 1; j <= ESAMI; j++) {
                    printf("Studente %d: %.2f \n", j, mediaEsami[j]);
                }
                break; // fine esercizio 4

            case SCELTA_0://termina programma
                printf("Programma termito.\n");
                break;

            default: //caso valore inserito non valido
                printf("Valore immesso non valido.");
        }
    } while (scelta != 0); // fine esercizio 1

    return 0;
}