# LFA - Proiect 1
# Realizator - Bratu Dragos
# Coordonator - Cosmin-Silvian Alexandru
## Enuntul cerintei:
#### Pentru un automat finit si un cuvant dat, sa se decida daca acel cuvant apartine sau nu limbajului recunoscut de automat. 
   
## Variabile folosite:

* int automat[100][100]: matricea automatului;
Pentru reprezentarea automatului si a legaturilor,am folosit o matrice,in care elementele a[stareInitiala][literaLegatura] = stareFinala au urmatoarea configuratie:
  * stareInitiala- variabila de tip int pentru starea din care pleaca legatura;
  * literaLegatura- variabila de tip char ce reprezinta litera de legatura intre cele doua stari;
  * stareFinala- variabila de tip int ce reprezinta starea in care ajunge legatura.
* int iesire[100]: tablou unidimensional pentru stocarea starilor de iesire;
* int i,j: contori pentru instrunctiunile repetitive
* int numarStari: numarul total al starilor;
* int numarLegaturi: numarul total al legaturilor;
* int numarIesiri: numarul starilor de iesire;
* int stareInitiala: variabila folosita in citirea matricii (starea din care pleaca legatura) si reprezinta in
algoritmul in sine starea actuala in care se afla cuvantul;
* char literaLegatura: variabila folosita in citire,este litera prin care se face legatura;
* int stareFinala: variabila folosita in citire,reprezinta starea in care ajunge legatura;
## Descrierea algoritmului:
* initializez elementele matricei cu -1 pentru a incepe cu un automat vid(nicio stare,nicio legatura);
* se citesc numarul de stari,numarul de legaturi,starea de inceput a automatului;
* pentru fiecare legatura,se citeste starea din care pleaca legatura (stareInitiala),litera de legatura(literaLegatura) si starea in care ajunge legatura,in aceasta ordine(stareFinala).Dupa fiecare citire a acestui triplet,se marcheaza in matricea automatului legatura,dupa formula:
a[stareInitiala][literaLegatura-31] = stareFinala;
  * Observatie : se scade 31 din litera pentru ca,in codul
ASCII,caracterele ce pot fi scrise de la tastatura incep de la numarul 32.Astfel,in reprezentarea interna a matricii,a doua coordonata incepe de la 1;
* se citeste numarul starilor de iesire;
* se citesc starile de iesire si se salveaza intr-un tablou unidimensional(iesire[]);
* se citeste cuvantul ce trebuie verificat;
 
### Verificarea in sine se face dupa urmatorii pasi:
* Se verifica daca din starea actuala exista un drum cu litera de legatura egala cu litera prefix a cuvantului de verificat:
  * in cazul in care exista,se merge pe legatura,se schimba starea si se sterge litera prefix a cuvantului;
  * in caz contrar,cuvantul nu indeplineste
conditiile si algoritmul se incheie,afisand mesajul “nu apartine”;
* Daca am ajuns la cuvantul vid,atunci se verifica daca starea in care se afla este o stare de iesire:
  * in cazul favorabil,cuvantul apartine limbajului si un mesaj sugestiv este afisat;
  * in caz contrar,cuvantul nu indeplineste conditiile si algoritmul se incheie,afisand mesajul
“nu apartine”;
