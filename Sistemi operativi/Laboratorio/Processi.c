/*puntatore generico --> puntatore che punta a variabile di tipo generico, impreciso*/

void *p;

/*Ogni puntatore può essere forzato a puntare a void tramite l'opreazione di cast 
prima di deferenziare un puntatore generico bisogna fare un cast al tipo originario della variabile a cui punta*/

int a, b;
void *p;
...
p = (void *) &a; /*P punta alla variabile intera a*/
b =* ((int *)p)+1 /*Eseguo cast prima, di deferenziare*/

Puntatori a funzione 

/*Un puntatore ad una variabile è l'indirizzo della prima cella di memoria dove si trova il valore della variabile
il tipo della variabile (int, char, Char*, Struct) determina il numero di byte/word necessari per memorizzare il suo valore*/

int a;
long b;
struct {...} c;
void *p,*q,*r;


/*Fino a quando non differente, non è necessario conoscerne il tipo*/

/*Sviluppare funzioni generiche e a passare come parametro di una funzione un'altra funzione
i puntatori a funzione si dichiarano in questo modo*/

tipo (*nome_funzione) (tipo part1, tipo part2) 

/*la parentesi attorno a *nome_funzione è necessaria, senza parentesi indica una funzione che restituisce un valore di tipo*/
/*Tale funzioni può essere parametro di un'altra */

funzione2 (tipo part1,\\
          tipo (*nome_funzione)(tipo part1, tipo part2))

/*PROCESSI*/

/*Processo
     - attivita di elaborazione guidata da un programma
     - Istanza di un programma in esecuzione
il processo è identificato da un PID (Processs Identifier)
per ogni processo attivo il SO deve mantenere in memoria una immagine che possiamo vedere suddivisa in 3 parti : 
    - Codice : in genere condiviso e read-only
    - Dati : globali, stack, heap
    - Dati processo/SO: interazione fra processo e S.O
*/

/*Creazione di un processo*/

/* Unix un processo si crea con una chiamata di sistema */
                Fork ();
/*Duplica il processo in esecuzione, creadone una copia  quasi
    - ha una copia dell'immagine
    - un diverso PID
    - La funzione fork restituisce al processo padre il PID del figlio (valore =/ 0)
    - il nuovo processo "nasce" uscendo anch'esso dalla chiamata di funzione fork() ottenendo però come risultato 0
*/


/*Processi: effetto della creazione*/
