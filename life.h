/*
  \file
  \authors informatica (CDS Fisica) 2018/19
  \brief AR: file di include
 */


/** 
    Crea una matrice (mxn) con h celle vive distribuite casualmente
    \param n numero delle righe
    \param m numero delle colonne
    \param h numero di celle vive da inserre

    \retval p puntatore alla nuova area (Se tutto e' andato bene)
    \retval NULL se si e' verificato un errore
*/
short ** crea_life (unsigned n, unsigned m, unsigned h) ;

/**
   stampa di life su stdout (FORNITO DAI DOCENTI NON MODIFICARE -- file life_docenti.c)
   \param l modello da stampare
   \param n numero di righe
   \param m numero di colonne
*/
void print_life (short** l, unsigned n, unsigned m);


/** dealloca la matrice che rappresenta life
    \param a modello da deallocare
    \param n numero di righe
*/
void distruggi_life (short** a, unsigned n) ;

/** legge dal file "s" una matrice (rappresentata con il seguente formato:
     numero_di_righe\n
     numero_di_colonne\n
     elementi della prima riga separati da spazi e teminati da \n
     elementi della seconda riga  separati da spazi e teminati da \n
     ....
     elementi dell'ultima riga  separati da spazi e teminati da \n
     ad esempio:
     2
     4
     0 0 1 1
     1 0 0 0
     e restitisce il puntatore alla matrice letta e 
     le sue dimensioni (in *pn e *pm)
     \param s nome del file
     \param pn puntatore alla variabile che conterra' il numero di righe
     \param pm puntatore alla variabile che conterra' il numero di colonne

     \retval p il puntatore alla nuova matrice letta da file (effettua anche l'allocazione)
     \retval NULL se si e' verifcato un errore (in questo caso *pn e *pm non vengono modificate)
 */
short** leggi_da_file (char * s, unsigned* pn, unsigned* pm);

/** scrive sul file di nome s il modello rappresentato dalla matrice a (nxm) 
    senza modificare a. Se il file gia' esiste viene sovrascritto
    \param s nome del file
    \param a puntatore alla matrice che rappresenta il modello
    \param n numero di righe
    \param m numero di colonne 
*/
void scrivi_su_file (char * s, short ** a, unsigned n, unsigned m) ;

/**
   Esegue un singolo passo di simulazione applicando le regole descritte nel PDF. Importante notare che le regole vanno applicate in ogni elemento di a facendo riferimento ai valori iniziali della matrice a, quindi eventuali modifiche possono essere riportate in a solo quando le regole sono state applicate ad ogni elemento.
   \param a puntatore alla matrice che rappresenta il modello 
   \param n numero di righe
   \param numero di colonne
 */
void step (short** a, unsigned n, unsigned m);
