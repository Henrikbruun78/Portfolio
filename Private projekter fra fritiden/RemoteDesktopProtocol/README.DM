## RDP-kommunikation mellem tablet og Raspberry Pi (wired setup - USB tethering) ##
Jeg købte en Samsung-tablet for at undersøge muligheden for at få lettere “on-the-go” adgang til en Raspberry Pi 5. I den forbindelse afprøvede jeg flere forskellige løsninger, blandt andet VNC og RDP.

Undervejs opdagede jeg, at det var muligt at lave en RDP-løsning via USB tethering, hvor der ikke er behov for Wi-Fi. Det betyder, at man gennem en USB-forbindelse kan få direkte adgang til en Raspberry Pi 5 uden brug af internet. Planen var at installere Kali Linux, så jeg kunne teste værktøjer som Wifite samt netværksværktøjer som eksempelvis nmap og tshark.

Processen førte mig først ind i FreeRDP, men jeg fik aldrig helt denne løsning til at fungere stabilt. Derefter prøvede jeg i stedet XRDP, som er en mere færdig og etableret løsning, og her lykkedes det at få forbindelsen til at fungere. I starten var forbindelsen dog ikke helt stabil, fordi IP-adressen ændrede sig efter genstart. Det løste jeg ved at konfigurere en statisk adresse, hvorefter systemet fungerede stabilt.

Jeg havde også købt et trådløst keyboard og en mus til opsætningen. Samlet set fungerede løsningen udmærket, men skriften i GUI’en var meget lille på tabletten. I terminalen fungerede det derimod fint.
