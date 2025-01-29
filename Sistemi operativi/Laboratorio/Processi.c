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


/*Processi: Schema di creazione*/
#include <unistd.h>
#include <sys/types.h>

pit_t pid;
  if((pid = fork ())<(pid_t)0)   {
    /* Errore nella fork */
    } else if (pid == (pid_t)0) {
        /*codice eseguito solo dal p.faglio*/
    } else {
        /* codice eseguito solo dal p.padre */
    }
/*Processi : attesa e terminazione */
/*
processo p1 può attendere la terminazione di un processo figlio  : 
        y = wait(&x);   Variante waitpid generale
 - in realtà non sempre c'è una attesa
 - il PID del processo terminato, viene restituito dalla funzione
 - l'interno in cui putnatore è stato pasasto a wait vengono messe informazioni su come p2 è termianto
 - informazioni vengono mantenute nella tabella dei processi dopo che un processo termina, in attesa di essere lette con wait
    - se non ci sono processi figli in esecuzione, wait blocca il processo che lo ha generato, 
      volta che sono state lette, per default l'elemento della tabella relativo al processo viene etichettato libero.
      da non occupare un posto.
P1 ha almeno un processo figlio p2 terminato che non è ancora stato "aspettato", se p1 ha processi figli non temrinati, viene sospeso finoa  quando uno di questi termini.
R :  dalla chiamata si esce subito con errore
se p1 viene sospeso, rimarrrebbe sospeso per sempre.
*/

/*Processi : esecuzione di un programma*/
/*
Clonare un processo identico non apre molto uitle, con if (fork()==0)
  - bispgma scrivere nello stesso programma l'intero codice eseguito dal p.figlio
in effetti, nel ramo del p.figlio si può usare una chiamata di sistema della famiglia exec
la precisione sono diverse funzioni C che permettono di accedere alla stessa chiamata di sistema qui semplificate in : 
    exec(nome_file_eseguibile)
*/

/*Processi : exec in dettaglio */
/*
int execl(const char *pathname, char *const argv []);
   Sostituiscono il codice attuali del processo chiamate con quelli dell'eseguibile pathname, restituisce -1 in caso di errore
   la modalità con cui si passano gli argomenti
   execl si specifica una lista di argomenti da pasasre all'eseguibile temrinati da NULL. [execl("/bin/ls", "ls",, "-l", (char *) NULL);]
   execv s passa un vettore di stringhe contenente gli argomenti da passare all'eseguibile temrianti da NULL : 
    - ARG = {"ls","-l", NULL}
    - execv("/bin/ls", arg);
int execlp(const char *file, const char *arg0, ...(char*)null);
int execvp(const char *file, char *const argv[]);
    - sostituiscono il codice attuali del processo chiamate con quelli dell'eseguibile filename, restituisce -1 in caso d'errore
 in execlp/execvp il nome dell'eseguibile cercandolo nelle directory specificate in path, la variabile d'ambiente viene ereditata dal processo chiamate.
*/