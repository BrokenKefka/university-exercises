/**
 * NOME:        Inserire nome studente qui
 * COGNOME:     Inserire cognome studente qui
 * MATRICOLA:   Inserire matricola studente qui
 */

/** === DESCRIZIONE ====================================================================================================
 * CONTESTO: Il Prof. Loddo vuole un programma che monitori i prezzi di settimana in settimana per i prodotti principali di Apple:
 * iPhone, Apple Watch, MacBook e iPad.
 *
 * OBIETTIVO: Scrivere un'applicazione in C che registri i prezzi ogni settimana e poi calcoli le statistiche su questi dati.
 *
 * SVOLGIMENTO: Il lavoro è diviso in tre parti:
 * 1.  Creare un menu per far scegliere all'utente cosa fare (ESERCIZIO 1).
 * 2.  Gestione e manipolazione dei dati attraverso matrici/array (ESERCIZI 2, 3).
 * 3.  Stampare  a schermo dei risultati ottenuti (ESERCIZIO 4).
 *
 * CONSIGLI: Risolvere gli esercizi in ordine di numerazione, ma non rimanere bloccati su un esercizio troppo a lungo.
 * L'ordine crescente degli esercizi non rappresenta una difficoltà crescente.
 * VALUTAZIONE: Gli esercizi hanno un punteggio. Se svolti tutti correttamente si raggiunge il 30.
 * Sono valutati, inoltre, i seguenti aspetti: stile e organizzazione del codice, uso delle best practice, commenti.
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
#define GENERARE 1	// Costante per scelta menu GENERARE
#define CALCOLARE 2	// Costante per scelta menu CALCOLARE
#define STAMPARE 3	// Costante per scelta menu STAMPARE
#define TERMINARE 0	// Costante per scelta menu TERMINARE
#define MIN_PREZZO 50000	// Prezzo minimo dispositivi non Apple Watch esteso per agevolare generazione float
#define MAX_PREZZO 99900	// Prezzo massimo dispositivi non Apple Watch esteso per agevolare generazione float
#define MIN_PREZZO_WATCH 22500	// Prezzo minimo Apple Watch per agevolare generazione float
#define MAX_PREZZO_WATCH 66500	// Prezzo massimo Apple Watch per agevolare generazione float
#define COEFF 100.00	// Coefficiente, già float, per la conversione in float con due cifre decimali
#define NUM_DISPOSITIVI 4	// iPhone, iPad, MacBook, Apple Watch
#define NUM_GIORNI 7	// Giorni della settimana
#define ID_IPHONE 0	// Indice iPhone
#define ID_WATCH 1 // Indice Apple Watch
#define ID_MACBOOK 2 // Indice MacBook
#define ID_IPAD 3 // Indice iPad
/** Fine macro studente */

int main(void)
{

	srand(time(NULL)); // Inizializzazione del generatore di numeri casuali

    /** Variabili studente */
	float prezzi[NUM_DISPOSITIVI][NUM_GIORNI] = {0}; // Matrice dei prezzi
	float prezzi_massimi[NUM_GIORNI] = {0}; // Array dei prezzi piu' alti giornalieri
	int dispositivo_piu_costoso[NUM_GIORNI] = {0}; // Array dei dispositivi piu' costosi giornalieri
	int scelta = 0, i = 0, j = 0; // Variabili di controllo
	float max_prezzo = 0.0; // Variabile per il prezzo massimo giornaliero
	int dispositivo_max = 0; // Variabile per il dispositivo con il prezzo massimo giornaliero
	int indice_dispositivo = 0;	// Indice del dispositivo piu' costoso in un giorno
	int piu_costoso_index = 0;	// Indice del dispositivo piu' volte piu' costoso durante la settimana

	int conteggio[NUM_DISPOSITIVI] = {0}; // Array per il conteggio delle volte che un dispositivo e' stato il piu' costoso
    /** Fine variabili studente */

    /* === ESERCIZIO 1 (MENU) ================================================================================
     * Realizzare un menu che, ciclicamente, permetta di scegliere tra le seguenti opzioni:
	 * TASTO 1) GENERARE (ESERCIZIO 2);
	 * TASTO 2) CALCOLARE (ESERCIZIO 3);
	 * TASTO 3) STAMPARE (ESERCIZIO 4);
	 * TASTO 0) TERMINARE.
     */
	do // Inizio ESERCIZIO 1
	{
		// Stampa del menu
		printf("\nMenu:\n");
		printf("1) GENERARE\n");
		printf("2) CALCOLARE\n");
		printf("3) STAMPARE\n");
		printf("0) TERMINARE\n");
		printf("Scegli un'opzione: ");
		scanf("%d", &scelta);

		// Gestione delle scelte
		switch (scelta)
		{
			/* === ESERCIZIO 2 (GENERAZIONE) ================================================================================
			 * Una matrice float 4x7 rappresenta i prezzi dei 4 dispositivi iPhone, Apple Watch, MacBook, ed iPad
			 * nei 7 giorni di una settimana. Generare la matrice considerando che il prezzo deve essere generato casualmente
			 * con due cifre decimali utili e compreso tra 500.00 e 999.00 euro se si tratta di un iPhone, iPad, Macbok;
			 * deve essere compreso tra 225.00 e 665.00 se si tratta dell'Apple Watch.
			 *
			 * ESEMPIO DI MATRICE GENERATA:
			 * (Ogni riga rappresenta un dispositivo, ogni colonna un giorno)
			 *
			 * iPhone      970.55  820.44  700.12  880.33  920.10  995.00  930.77
			 * AppleWatch  450.10  400.22  300.50  550.30  620.40  640.55  650.00
			 * iPad        780.22  750.11  690.30  860.44  810.66  940.12  870.55
			 * MacBook     899.99  820.35  770.11  910.22  940.00  960.10  950.99
			 */
			case GENERARE:	// ESERCIZIO 2
				// Chiamata alla funzione per generare la matrice
				printf("Generazione della matrice...\n");
				for (i = 0; i < NUM_DISPOSITIVI; i++)	// Scorro la matrice per riga (dispositivo)
				{
					for (j = 0; j < NUM_GIORNI; j++)	// Scorro la matrice per colonna (giorno della settimana)
					{
						if (i == ID_WATCH)
						{	// Se sono alla riga con indice 1, si tratta dell'Apple Watch
							prezzi[i][j] = (rand() % (MAX_PREZZO_WATCH - MIN_PREZZO_WATCH + 1) + MIN_PREZZO_WATCH) /
							               COEFF; // Generazione prezzo Apple Watch
						}
						else
						{
							// Generazione prezzo per gli altri dispositivi
							prezzi[i][j] = ((rand() % (MAX_PREZZO - MIN_PREZZO + 1) + MIN_PREZZO)) / COEFF;
						}
					}
				}
				break;	// Fine ESERCIZIO 2
			case CALCOLARE:
				/*=== ESERCIZIO 3 (STATISTICHE) ================================================================================
				 * Un array float di 7 elementi rappresenta il prezzo piu' alto giornaliero tra i 4 dispositivi.
				 * Un array int di 7 elementi rappresenta il dispositivo (0=iPhone, 1=Apple Watch, 2=MacBook, 3=iPad) con il prezzo
				 * piu' alto giornaliero. Calcolare entrambi gli array, a partire dalla matrice dei prezzi generata nell'esercizio 2.
				 * Infine, calcolare quale dispositivo e' stato il piu' volte piu' costoso durante la settimana.
				 */
				printf("Calcolo degli array...\n");
				/* Calcolo del prezzo piu' alto giornaliero. Seguo la seguente logica: "fisso" il giorno (colonna)
				 * con il FOR più esterno, e scorro i dispositivi (righe) per trovare il prezzo piu' alto in quel giorno.
				 * Ripeto per tutti i giorni.
				 */
				for (j = 0; j < NUM_GIORNI; j++) // Scorro i giorni (colonne)
				{
					/* Per ogni colonna j-esima, devo identificare il massimo quindi, per comodità, inizializzo
					 * il massimo con il primo elemento della colonna (elemento [0][j]) e setto il dispositivo correlato
					 * al dispositivo 0 (iPhone). Poi scorro la colonna (giorno) confrontando ogni elemento con il
					 * massimo attuale, identificato fino a quel momento.
					 * Se trovo un elemento più grande, aggiorno il massimo e il dispositivo correlato.
					 */
					max_prezzo = prezzi[0][j];
					dispositivo_max = 0;
					for (i = 1; i < NUM_DISPOSITIVI; i++)	// Fissata la colonna j-esima, scorro le righe (dispositivi)
					{
						if (prezzi[i][j] > max_prezzo) // Confronto l'elemento corrente prezzi[i][j] con il massimo attuale
						{
							max_prezzo = prezzi[i][j];	// Aggiorno il massimo
							dispositivo_max = i;	// Aggiorno il dispositivo correlato
						}
					}
					/* Al termine del FOR interno, ho trovato il massimo per il giorno j-esimo. Lo salvo nell'array
					 * prezzi_massimi (array di dimensione pari al numero di giorni) e il dispositivo correlato
					 * nell'array dispositivo_piu_costoso (anch'esso di dimensione pari al numero di giorni).
					 */
					prezzi_massimi[j] = max_prezzo;	// Salvataggio del prezzo massimo giornaliero
					dispositivo_piu_costoso[j] = dispositivo_max; // Salvataggio del dispositivo con il prezzo massimo giornaliero
				}

				/* Al termine del calcolo dei due array, devo identificare quale dispositivo e' stato il piu' volte
				 * piu' costoso durante la settimana. Per fare cio', utilizzo un array di conteggio (conteggio)
				 * di dimensione pari al numero di dispositivi, inizializzato a zero. Scorro l'array dispositivo_piu_costoso
				 * e per ogni elemento incremento il corrispondente elemento nell'array conteggio.
				 * Al termine, l'elemento con il valore piu' alto nell'array conteggio rappresenta il dispositivo
				 * che e' stato il piu' volte piu' costoso durante la settimana.
				 */
				for (j = 0; j < NUM_GIORNI; j++) // Scorro l'array dispositivo_piu_costoso, di dimensione pari al numero di giorni
				{
					indice_dispositivo = dispositivo_piu_costoso[j];	// Identifico il dispositivo piu' costoso nel giorno j-esimo
					conteggio[indice_dispositivo]++; // Incremento il conteggio per quel dispositivo
					/* NB: la logica qui sopra si può scrivere in una sola riga come:
					 * conteggio[dispositivo_piu_costoso[j]]++;
					 */
				}

				/* Al termine del conteggio, identifico l'indice del dispositivo con il conteggio piu' alto.
				 * Inizializzo l'indice con 0 (iPhone) e scorro l'array conteggio confrontando ogni elemento
				 * con il valore massimo attuale. Se trovo un elemento piu' alto, aggiorno l'indice.
				 */
				piu_costoso_index = 0;
				for (i = 1; i < NUM_DISPOSITIVI; i++)	// Scorro l'array conteggio di dimensione pari al numero di dispositivi
				{
					if (conteggio[i] > conteggio[piu_costoso_index]) // Confronto l'elemento corrente con il massimo attuale
					{
						piu_costoso_index = i;	// Aggiorno l'indice del dispositivo piu' volte piu' costoso
					}
				}
				break;	// Fine ESERCIZIO 3

			case STAMPARE: // ESERCIZIO 4
				/* === ESERCIZIO 4 (STAMPA) ================================================================================
				 * Stampare la matrice dei prezzi, l'array dei prezzi piu' alti giornalieri e il nome del dispositivo che e' stato
				 * il piu' volte piu' costoso durante la settimana.
				 * Esempio:
				 *
				 * Matrice dei prezzi settimanali:
				 * 990.58 777.25 699.99 600.00 790.50 880.75 999.80
				 * 450.68 300.44 400.55 350.16 500.19 600.21 650.88
				 * 850.05 720.15 680.33 590.44 750.55 830.33 900.50
				 * 920.71 770.22 690.66 580.34 730.11 840.30 950.70
				 *
				 * Prezzi piu' alti giornalieri:
				 * 990.58 777.25 699.99 600.00 790.50 880.75 999.80
				 *
				 * Dispositivo piu' volte piu' costoso durante la settimana: iPhone
				 */
				printf("Stampa dei risultati...\n");
				// Stampa della matrice dei prezzi
				for (i = 0; i < NUM_DISPOSITIVI; i++) // Scorro la matrice per riga (dispositivo)
				{
					for (j = 0; j < NUM_GIORNI; j++)	// Scorro la matrice per colonna (giorno della settimana)
					{
						printf("%6.2f\t", prezzi[i][j]); // Stampa dell'elemento corrente con due cifre decimali
					}
					printf("\n");	// A capo dopo ogni riga
				}

				printf( "\nPrezzi piu' alti giornalieri:\n" );
				for (j = 0; j < NUM_GIORNI; j++) // Scorro l'array dei prezzi piu' alti giornalieri
				{
					printf("%6.2f\t", prezzi_massimi[j]); // Stampa dell'elemento corrente con due cifre decimali
				}

				printf( "\nDispositivo piu' volte piu' costoso durante la settimana: " );
				switch (piu_costoso_index)
				{
					case ID_IPHONE:
						printf("iPhone.\n");
						break;
					case ID_WATCH:
                        printf("Apple Watch.\n");
						break;
					case ID_MACBOOK:
						printf("MacBook.\n");
						break;
					case ID_IPAD:
						printf("iPad.\n");
						break;
					default:
						printf("Errore nell'identificazione del dispositivo.\n");
				}
				break; // Fine ESERCIZIO 4
			case TERMINARE:
				printf("Terminazione del programma.\n");
				break;
			default:
				printf("Scelta non valida. Riprova.\n");
		}
	} while (scelta != 0);	// Fine ESERCIZIO 1

	return 0;

}
