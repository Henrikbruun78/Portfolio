### Virtualisering og virtuelle miljøer

På andet semester blev der arbejdet med **virtualisering** som teknologisk fundament for moderne IT-infrastruktur. Fokus var på at forstå, hvordan hardware-ressourcer kan abstraheres og deles mellem flere systemer, samt hvordan virtuelle miljøer anvendes til test, udvikling og sikkerhed.

Undervisningen tog udgangspunkt i **VMware Workstation**, hvor der blev arbejdet med opbygning og administration af virtuelle maskiner. Her blev begreber som hypervisor, host- og guest-operativsystemer gennemgået, og der blev opnået praktisk erfaring med installation af Linux-baserede gæste-systemer, herunder Ubuntu.

Der blev arbejdet med **ressourcestyring**, hvor CPU, RAM, lager og netværk tildeles virtuelle maskiner. Fokus var på korrekt dimensionering og forståelse for, at virtuelle ressourcer ikke nødvendigvis svarer 1:1 til fysiske ressourcer. I den forbindelse blev der også arbejdet med strukturering af virtuelle diske og forståelse for, hvordan virtuelle maskiner reelt består af konfigurations- og diskfiler.

Et centralt element i forløbet var **virtuel netværkskonfiguration**. Her blev der arbejdet med de tre grundlæggende netværkstyper:
- **NAT**, hvor virtuelle maskiner placeres i et isoleret subnet med adgang til eksternt net via hosten  
- **Bridged**, hvor virtuelle maskiner optræder direkte på det fysiske netværk  
- **Host-only**, hvor kommunikation er begrænset til host og virtuelle maskiner  

Gennem praktiske øvelser blev der opbygget flere virtuelle maskiner, som blev testet i forskellige netværksopsætninger, herunder ping-tests og netværksanalyse. Dette gav en konkret forståelse for, hvordan netværksadgang, isolation og eksponering ændres afhængigt af valg af virtualiseringsmodel.

Samlet set gav virtualiseringsforløbet en solid forståelse for, hvordan virtuelle miljøer anvendes til at opbygge fleksible, sikre og reproducerbare systemer. Denne viden har været central i senere arbejde med netværkssikkerhed, MQTT-systemer og komplekse IoT- og embedded-arkitekturer, hvor isolerede test- og udviklingsmiljøer er afgørende.


### Network Security og netværksbeskyttelse

Som en del af andet semester blev der arbejdet med **netværkssikkerhed** med fokus på segmentering, firewall-arkitektur, overvågning og praktisk beskyttelse af netværk. Undervisningen kombinerede teoretiske sikkerhedsprincipper med hands-on øvelser i virtuelle miljøer.

Forløbet startede med en introduktion til grundlæggende sikkerhedsbegreber, herunder **defense in depth**, risikoforståelse og netværkssegmentering. Der blev arbejdet med opdeling af netværk ved hjælp af **VLAN**, **DMZ-zoner** og **NAT-konfigurationer**, hvilket gav forståelse for, hvordan angrebsflader kan reduceres gennem arkitektur og isolering.

I den praktiske del blev der arbejdet med **VMware Workstation**, hvor virtuelle netværk blev opbygget og anvendt som testmiljø. Her blev der oprettet forskellige netværkstyper (NAT, bridged og host-only) for at simulere realistiske netværksscenarier.

Der blev arbejdet indgående med **pfSense** som firewall- og routerplatform. Dette omfattede opsætning af firewall-regler, NAT og etablering af en DMZ-zone. Øvelserne gav praktisk erfaring med, hvordan trafik styres og kontrolleres mellem interne og eksterne netværk.

Som supplement hertil blev der introduceret til **sårbarhedsscanning og netværksanalyse** ved brug af værktøjer som **Nmap** og **Zenmap**. Her blev der arbejdet med scanning af netværk, identifikation af åbne porte og forståelse af forskellen mellem defensive og offensive sikkerhedsperspektiver (blackhat vs. whitehat).

Endvidere blev der arbejdet med **Wireshark** til analyse af netværkstrafik. Øvelserne fokuserede på pakkeopsamling, protokolanalyse og forståelse af, hvordan data bevæger sig gennem netværket på lavt niveau.

Samlet set gav network security-forløbet en praktisk og arkitektonisk forståelse for, hvordan netværk kan designes og sikres mod uønsket adgang. Erfaringerne fra segmentering, firewall-opsætning og trafik­analyse har haft direkte relevans for senere arbejde med IoT-systemer, MQTT-kommunikation og distribuerede embedded løsninger.



### Webudvikling, databaser og systemintegration

På andet semester blev der arbejdet med webudvikling og databaser med fokus på at forbinde backend-logik, databaser og simple webgrænseflader til sammenhængende systemer. Undervisningen havde en praktisk tilgang, hvor målet var at forstå hele dataflowet fra input til lagring, behandling og visualisering.

Forløbet startede med en introduktion til **databaser og PostgreSQL**, herunder grundlæggende databasebegreber, datatyper og SQL-kommandoer som `CREATE`, `SELECT`, `WHERE` og `FROM`. Der blev arbejdet med både lokale installationer og cloud-baserede løsninger, hvilket gav forståelse for forskellen mellem on-premise og cloud-miljøer samt praktisk erfaring med administration via værktøjer som **pgAdmin**.

Herefter blev databaser koblet sammen med **Python**, hvor fokus var på at kommunikere med PostgreSQL via database-connectors og arbejde med data programmatisk. Der blev lagt vægt på struktur, læsbarhed og korrekt håndtering af forespørgsler og resultater.

Som en naturlig forlængelse heraf blev der introduceret til **webudvikling med Flask** som backend-framework. Her blev der arbejdet med opbygning af simple webapplikationer, routing, templating og samspillet mellem backend-logik og frontend. Frontend-delen omfattede grundlæggende **HTML og CSS**, herunder opbygning af sider, navigation og simple brugergrænseflader.

I denne sammenhæng blev der arbejdet med **CRUD-funktionalitet** (Create, Read, Update, Delete), hvor webapplikationer blev anvendt til at oprette, vise og opdatere data i PostgreSQL-databaser. Fokus var på at forstå

### Programmering og objektorienteret design

På andet semester blev programmeringsundervisningen udvidet fra grundlæggende struktur til **objektorienteret programmering (OOP)** og systematisk softwaredesign. Fokus var på at skrive mere vedligeholdbar, skalerbar og struktureret kode, der kunne indgå som en del af større systemer.

Forløbet startede med en repetition af **funktioner og moduler**, hvorefter der blev arbejdet med **struktureret programmering**. Her var fokus på klar programopbygning, ansvarlig opdeling af kode og anvendelse af flowcharts som værktøj til at visualisere programlogik og procesforløb.

Herefter blev der introduceret til **grafiske brugergrænseflader (GUI) i Python**, hvor simple interfaces blev opbygget for at koble programlogik til brugerinteraktion. Dette gav indsigt i samspillet mellem frontend-elementer og backend-funktionalitet.

En central del af semestret var introduktionen til **objektorienteret programmering**, hvor begreber som klasser, objekter, attributter og metoder blev grundlæggende forstået og anvendt i praksis. Dette blev efterfulgt af arbejde med **UML og design**, hvor klasser, relationer og systemstruktur blev modelleret før implementering.

I forlængelse heraf blev der arbejdet med centrale OOP-principper såsom:
- **arv**, hvor funktionalitet genbruges og udvides  
- **komposition og aggregation**, hvor systemer sammensættes af mindre, selvstændige komponenter  
- tydelig adskillelse af ansvar mellem klasser  

Disse principper blev understøttet af praktiske øvelser og visualisering via UML-diagrammer og værktøjer som PlantUML.

Samlet set gav programmeringsforløbet på andet semester en solid forståelse for objektorienteret tænkning og softwarearkitektur. Erfaringerne herfra har haft direkte betydning for senere arbejde med større kodebaser, embedded software, MQTT-baserede systemer og komplekse IoT-projekter, hvor struktur og design er afgørende.

### MQTT og IoT-kommunikation

Som en del af andet semester blev der arbejdet målrettet med **MQTT som kommunikationsprotokol** i forbindelse med IoT- og robotsystemer. Fokus var på forståelse af signalflow, systemdesign og pålidelig dataudveksling mellem enheder.

Forløbet startede med en introduktion til MQTT og dets rolle i distribuerede systemer, herunder publish/subscribe-modellen, emnestruktur og adskillelse mellem datakilder og datamodtagere. Dette blev sat i kontekst gennem et robotbilsprojekt, hvor signaler, kommandoer og sensordata skulle struktureres og transporteres korrekt mellem systemkomponenter.

Der blev arbejdet med **systemdesign og signalovervejelser**, hvor valg af signaltyper, opdeling af funktionalitet og kommunikationsveje blev analyseret. Her blev der lagt vægt på, hvordan et system kan opdeles i selvstændige moduler, der kommunikerer via veldefinerede MQTT-topics.

I den praktiske del blev der opbygget en **MQTT-baseret høstmaskine-case**, hvor der blev arbejdet med:
- oprettelse af databaser
- Python-baserede MQTT-clients
- håndtering af indkommende og udgående beskeder
- lagring og viderebehandling af data  

Derudover blev der arbejdet med **installation og konfiguration af en MQTT-server**, herunder forståelse for broker-rollen, netværksopsætning og klientforbindelser.

Som supplement til MQTT-arbejdet blev der arbejdet med **sensorer og UART-kommunikation**, herunder GPS- og TOF-sensorer. Her blev der fokuseret på forskellen mellem rå og raffinerede data samt på forståelse af seriel kommunikation og signalanalyse.

Samlet set gav MQTT-forløbet en praktisk og systemorienteret forståelse for, hvordan IoT-enheder kan kobles sammen via en letvægtsprotokol, og hvordan data kan struktureres, distribueres og anvendes i større systemer. Dette blev et centralt fundament for senere arbejde med IoT-arkitektur, dataopsamling og embedded systemer.

### Projektstyring og teknisk projektarbejde

På andet semester blev der arbejdet videre med **projektstyring** med fokus på planlægning, struktur, kvalitet og gennemførelse af tekniske projekter. Forløbet byggede oven på de grundlæggende projektledelsesprincipper fra første semester og havde en mere anvendelsesorienteret tilgang rettet mod semesterprojektet.

Undervisningen startede med en introduktion til **teamroller og samarbejde**, samt grundlæggende principper inden for projektledelse og opbygning af højtydende projektteams. Her blev der arbejdet med ansvar, rollefordeling og kommunikation i tekniske projektgrupper.

Herefter blev der arbejdet indgående med **Work Breakdown Structure (WBS)** og estimering. Projektet blev opdelt i håndterbare aktiviteter, som dannede grundlag for realistisk tidsplanlægning og ressourceoverblik. I denne fase blev der udarbejdet kravspecifikationer og aktivitetslister, som fungerede som styringsværktøjer gennem resten af projektet.

Der blev desuden arbejdet med **sekvensplanlægning, Gantt-diagrammer og kritisk sti**, hvor fokus var på at identificere afhængigheder mellem aktiviteter og forstå, hvilke opgaver der var tidskritiske for projektets samlede fremdrift. Dette gav indsigt i, hvordan ændringer og forsinkelser påvirker hele projektforløbet.

En væsentlig del af forløbet bestod af **rapportskrivning og dokumentation**, hvor der blev arbejdet med teknisk formidling, struktur og sammenhæng mellem krav, design, implementering og test. Dokumentationen blev løbende anvendt som aktivt styringsværktøj frem for blot som afsluttende aflevering.

Derudover blev der arbejdet med **kvalitetssikring og evalueringsformer**, herunder vurdering af projektresultater i forhold til opstillede mål og krav. Forløbet blev afsluttet med præsentation af semesterprojektet, hvor både teknisk løsning, projektforløb og business case blev formidlet.

Samlet set gav projektstyringsforløbet på andet semester en praktisk og struktureret tilgang til gennemførelse af tekniske projekter, hvor planlægning, kvalitet og dokumentation blev integreret direkte i det tekniske arbejde. Dette har haft stor betydning for senere arbejde med komplekse systemer og selvstændige projekter.

