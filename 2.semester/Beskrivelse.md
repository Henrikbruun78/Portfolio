

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

