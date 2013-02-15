#include <stdio.h>
#include <stdlib.h>

char c; //Action

char* myInfo(int);
char* wQuest(int);

void flush(){
	fflush(stdout);
	fflush(stdin);
}

int end(){
	flush();
	scanf("%c",&c);
	return 0;
}

int main() {
	printf("WILLKOMMEN IN SCHMARNIA\n\t8-hour-games 3\n");
	printf("Du hast eine Aufgabe:\n");
	printf("Finde die Prinzessin, rette den Frosch und stirb nicht!\n\n");
	
	int frog=0;
	int princess=0;
	int me=0;
	int erkaeltet=0;
	int katze=0;
	int stein=0;
	int zylinder=0;
	
	int kater=1;

	printf("Dein Name ist Jhonny. Du stehst in einer Huette aus Holz, die du noch nie\n");
	printf("vorher gesehen hast und dir brummt der Schaedel schlimmer als er sollte\n");
	beginning:
	flush();
	printf("(u)mgucken, (s)chlafen");
	if(me==0) printf(wQuest(me));
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'w' : if(me<1) printf(myInfo(me++)); goto beginning;
		case 's' : printf("zzzzZZZZzzzzZZZZzzzzz chrm... davon wird der Schaedel auch nicht besser.\n");
				   printf("Zumindest nicht solange du kein Bett hast.\n"); goto beginning;
		case 'u' : printf("Die Huette hat eine Tuer die in einzelteilen im Raum verteilt liegt,\n");
				   printf("und 2 Fenster die beide eingeworfen sind und durch die es zieht\n");
				   printf("Ein Bett steht direkt hinter dir. Was nun?\n"); break;
		default  : goto beginning;
	}
	hut:
	flush();
	printf("(r)ausgehen");
	if(kater) printf(", (s)chlafen");
	if(me<=1) printf(wQuest(me));
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'w' : if(me<2) printf(myInfo(me++)); goto hut;
		case 's' : printf("Du legst dich schlafen und langsam lassen die Kopfschmerzen nach...\n");
				   printf("Das tut gut... Dafuer hast du dich erkaeltet... na super\n");
				   kater=0; erkaeltet=1; goto hut;
		case 'r' : printf("Du gehst raus und guckst dich um... sieht schnuckelig aus!\n");
				   printf("Eine dunkle Gasse, viele Mueltonnen, eine schwarze Katze, Kaputte Beleuchtung.\n"); 
				   printf("Und dazu ist sie auch noch gewunden, sodass man das Ende nicht sehen kann.\n"); break;
		default  : goto hut;
	}
	gutter:
	flush();
	printf("(a)ugen zu und durchrennen, (m)ueltonnen?");
	if(!katze) printf(", (k)atze!!!");
	if(me==0 || me==2) printf(wQuest(me));
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'w' : if(me==0 || me==2) printf(myInfo(me++)); goto gutter;
		case 'a' : if(erkaeltet && !katze){
						printf("Du niesst, dass macht die Katze aggressiv.\nSie toetet dich.");
						return end();
					} else{
						printf("Wirklich eine gute Idee die Augen dabei zuzumachen, so siehst du wenigstens\n");
						printf("nicht, gegen was fuer ekeliges Zeug du so rennst!\n");
						printf("Als du die Augen wieder aufmachst steht eine ziemlich dicke Frau vor dir,\n");
						printf("die vorwurfsvoll hinter dich zeigt... Sie stinkt genau so wie die Gasse vorhin.\n"); break;
					}
		case 'k' : printf("Ja, mega Niedlich... Eine Streunerkatze... naja... du willst sie ja mitnehemen.\n");
				   katze=1; goto gutter;
		case 'm' : printf("Tjoa, davon gibts hier haufenweise welche, sie versuchen sich gegenseitig im\n");
				   printf("Gestank zu uebertreffen. Ich wuerde mich dafuer in deiner Lage ja nicht\n"); 
				   printf("interressieren, aber du fandest es SO interressant, dass du 'm' eingeben musstest.\n");
				   printf("Was ein Glueck wohne ich nicht bei dir zu Hause!\n"); goto gutter;
		default  : goto gutter;
	}
	valkyrie:
	flush();
	printf("(u)mdrehen und rennen, (h)allo werte Dame, um(g)ucken");
	if(katze) printf(", mit (k)atze angreifen");
	if(me<=1 || me==3) printf(wQuest(me));
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'w' : if(me<=1 || me==3) printf(myInfo(me++)); goto valkyrie;
		case 'h' : printf("\"Seien sie gegruesst edles Geschoepf voll zartester Schoenheit!\"\n");
				   printf("Gute Nachrichten: sie ignoriert dich, Schlechte Nachrichten: du redest weiter\n");
				   printf("Ich sollte Geld dafuer verlangen dir alles beschreiben zu muessen!\n"); goto valkyrie;
		case 'u' : printf("Du drehst dich um und rennst zurueck. Ich bezweifle allerdings, dass dir\n");
				   printf("das sonderlich viel bringt, die wird warscheinlich stehenbleieben.\n"); goto gutter;
		case 'g' : printf("Tjoa, du siehst nicht viel mehr als vorher. Okey, die meisten Muelleimer sind\n");
				   printf("umgestossen und ihr Inhalt liegt auf der Strasse verstreut.\n"); 
				   printf("Bei manchen Haufen sieht man sogar deine Fussabdruecke!\n"); goto valkyrie;
		case 'k' : if(katze){
						printf("Die Katze zerkratzt ihr sauber das Gesicht! Yar, erster Mob tod!\n");
				   		if(erkaeltet){
							printf("Danach scheint die Katze aber keine Lust mehr zu haben bei dir zu bleiben.\n"); 
							katze=0;
						} else {
							printf("Danach kriecht die Katze brav zurueck in deine Tasche.\n");
							printf("Was ich davon halte weißt du ja bereits.\n");
						}
				   		printf("Der Weg ist frei, vor dir Liegt eine etwas sauberere Gasse. Du kannst zwischen\n"); 
				   		printf("einem Schaufenster, einem Karren und einem Alten Mann mit Zylinder waehlen.\n"); break;
				   }
		default  : goto valkyrie;
	}
	street:
	flush();
	printf("(i)ch will aber weitergehen, (k)arren anschauen");
	if(!zylinder) printf(", (z)ylindermann ansprechen");
	if(stein) printf(", (s)chaufenster einwerfen");
	else printf(", (s)chaufenster angucken");
	if(me==0 || me==2 || (me>=4 && me<=5)) printf(wQuest(me));
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'w' : if(me==0 || me==2 || (me>=4 && me<=5)) printf(myInfo(me++)); goto street;
		case 'i' : printf("\n");
				   printf("\n"); goto street;
		case 'k' : printf("\n");
				   printf("\n");
				   printf("\n"); break;
		default  : goto street;
	}
	
	if(frog && princess){
		printf("HERZLICHEN GLUECKWUNSCH!\nDu hast das Spiel gewonnen!");
		return end();
	} else {
		printf("Tja, das ueben wir nochmal, die fehlt ");
		if(!frog && !princess) printf("Frosch und Prinzessin!");
		else if(!frog) printf("der Frosch!");
		else printf("die Prinzessin!");
		return end();
	}
}

char* wQuest(int me){
	switch(me){
		case 0 : return ", (w)er ich bin?";
		case 1 : return ", (w)er bin ich denn nun?";
		case 2 : return ", (w)er BIN ich?!?";
		case 3 : return ", (w)as?...ein...Jhonny?";
		case 4 : return ", (w)ieso 2 Arme, 2 Beine?";
		case 5 : return ", (w)ar das gerade ein \"3 Beine\"?";
		case 6 : return ", (w)er bin ich? =)";
		case 7 : return ", (w)er bin ich? So schwer ist die Frage doch nicht!";
		default : return "";
	}
}

char* myInfo(int me){
	switch(me){
		case 0 : return "Wie bereits gesagt, du bist Jhonny, reicht dir das nicht oder was?\n";
		case 1 : return "Ja... Du bist immer noch Jhonny... Hat sich nix dran geaendert...\n";
		case 2 : return "Ein... Jhonny? Du koenntest mir aber auch echt mal nen Tipp geben, was du nun\n"
						"eigentlich von mir willst.\n";
		case 3 : return "Ja! 2 Arme, 2 Beine, eine uebertriebene Neugier... Jhonny halt!\n";
		case 4 : return "Okey, das mit den 2 Beinen war gelogen, es sind 3, keine Angst.\n";
		case 5 : return "Nicht okey? hm... dann sind es... 4? Wieviele Beine haben DEINE Jhonnys denn?\n";
		case 6 : return "Ach, auf einmal keine Diskussion mehr ueber die Anzahl DEINER Gliedmaßen?\n";
		case 7 : return "Ist ein Spiegel auf deiner Existenzebene derart Teuer?\n";
		default : return "Jhonny\n";
	}
}


//int cheat(){
//	printf("Netter Versuch Buerschchen! Leider muss ich dich dafuer toeten... CHEATER!");
//	end();
//}
