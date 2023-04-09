PROIECT #1 PROGRAMARE ORIENTATĂ PE OBIECTE

	 AGENȚIE DE MARKETING - CREATIVEAGENCY

Clasele implementate:

AGENTIE
-Clasa de bază a proiectului unde sunt prezente cele mai multe metode și care gestionează celelalte clase, având un număr maxim de contracte și servicii predefinite, variabile pentru numele agenției, serviciile, numărul de servicii oferite, contractele active ale agenției și încasările totale.
CONTRACT
-Această clasă definește legătura dintre reclamă,agenție și client, având un număr maxim de servicii prestabilit, o durată exprimată în luni, procentul din încasări pe care îl încasează agenția, valoarea totală, serviciile prestate , data începerii, data finalizării și echipa care lucrează la proiect. 
ECHIPA
-Clasa Echipa este cea care are o legătură cu Contract , incluzând variabile precum numărul de membri, numărul de proiecte active pe care le are echipa , cât și numele membrilor.  
WEBSITE
-Clasa Website reprezintă website-ul propriu-zis pe care agenția îl poate realiza pentru client, având un preț, număr de pagini, număr de funcționalități, tipul design-ului cât și funcționalitățile declarate dinamic.
CLIENT
-Clasa Client cu ajutorul căreia se transmit serviciile de care acesta are nevoie, având un nume, reclamele pe care deja le folosește, email, telefon,  serviciile pe care le-a ales , dacă are deja website și capitalul pe care îl are disponibil pentru reclame.
RECLAMA
-Clasa Reclama care are variabile ce definesc platforma pe care se află, costul pe fiecare click al reclamei, impactul și interacțiunile pe care le are. 

Funcționalități:
Prin această aplicație clientul îți poate alege serviciul pe care nu îl are deja și care este în limita bugetului disponibil. 
Se poate crea un contract care are toate datele necesare întocmirii.
Agenția reține contractele pe care le are , cât și încasările de pe urma lor , reprezentat printr-un procent din valoarea totală.
Agenția poate adăuga servicii sau le poate actualiza estimând un randament pentru fiecare tip de reclamă.