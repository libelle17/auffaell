// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
const double& versnr= //α
#include "versdt"
;
#include "kons.h"
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "auffaell.h"
// fuer verschiedene Sprachen //α
char const *DPROG_T[T_MAX+1][SprachZahl]=
{
	// T_virtVorgbAllg
	{"virtVorgbAllg()","virtgeneralprefs()"},
	// T_pvirtVorgbSpeziell
	{"pvirtVorgbSpeziell()","pvirtspecialprefs()"},
	// T_virtMusterVorgb
	{"virtMusterVorgb()","virtsampleprefs"},
	// T_pvirtvorrueckfragen
	{"pvirtvorrueckfragen()","pvirtbeforecallbacks()"},
	// T_virtrueckfragen
	{"virtrueckfragen()","virtcallbacks()"},
	// T_virtpruefweiteres
	{"virtpruefweiteres()","virtcheckmore()"},
	// T_virtmacherkl_Tx_lgn
	{"pvirtmacherkl, Tx.lgn: ","pvirtmakeexpl, Tx.lgn: "},
	//	T_Fehler_beim_Pruefen_von
	{"Fehler beim Pruefen von: ","Error while examining: "},
	// T_st_k
	{"st","st"},
	// T_stop_l
	{"stop","stop"},
	// T_DPROG_anhalten
	{DPROG " anhalten","stop " DPROG},
	// T_anhalten
	{"anhalten()","stop()"},
	// T_Cron_Aufruf_von
	{"Cron-Aufruf von '","cron call of '"},
	// T_gestoppt
	{"' gestoppt.","' stopped."},
	// T_n_k
	{"n","n"},
	// T_dszahl_l
	{"dszahl","reccount"},
	// T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt
	{"Zahl der aufzulistenden Datensaetze = <zahl> statt","No. of listed entries = <no> instead of"},
	// T_Datenbank_nicht_initialisierbar_breche_ab
	{"Datenbank nicht initialisierbar, breche ab","database init failed, stopping"},
	// T_pvirtnachrueckfragen,
	{"pvirtnachrueckfragen()","pvirtbeforecheckmultiple()"},
	// T_pvirtfuehraus,
	{"pvirtfuehraus()","pvirtexecute()"},
	// T_in_pvirtfuehraus_pidw,
	{"in pvirtfuehraus(), pidw","in pvirtexecute(), pidw"},
	// T_virttesterg,
	{"virttesterg()","virtcheckresult()"},
	// T_virtzeigversion,
	{"virtzeigversion()","virtshowversion()"},
	// T_virtzeigueberschrift, 
	{"virtzeigueberschrift()","virtshowheadline()"},
	// T_Fuege_ein
	{"Fuege ein: ","Inserting: "}, //ω
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

struct TxB Tx((const char* const* const* const*)DPROG_T);
const char sep = 9; // geht auch: "[[:blank:]]"
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;
pidvec pidw; // wird zweimal verwendet, um auf Kindprozesse zu warten: in wegfaxen (auf die Faxarten) und in pvirtfueraus (auf korrigierefbox, -capi und -hyla
const unsigned ktage=1; // kurzes Intervall fuer Faxtabellenkorrektur, 1 Tag
const unsigned mtage=30; // mittleres Intervall fuer Faxtabellenkorrektur, 1 Monat
const unsigned ltage=73000; // langes Intervall fuer Faxtabellenkorrektur, 200 Jahre

using namespace std; //ω
hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG,/*mitcron*/1) //α
{
	hLog(violetts+"hhcl::hhcl()"+schwarz);
	// mitpids=1;
 // mitcron=0; //ω
} // hhcl::hhcl //α
// Hier neue Funktionen speichern: //ω
//α
// aufgerufen in lauf
void hhcl::virtVorgbAllg()
{
	hLog(violetts+Tx[T_virtVorgbAllg]+schwarz); //ω
	dhcl::virtVorgbAllg(); //α
} // void hhcl::virtVorgbAllg

// aufgerufen in lauf
void hhcl::pvirtVorgbSpeziell()
{
	hLog(violetts+Tx[T_pvirtVorgbSpeziell]+schwarz);
	virtMusterVorgb(); //ω
	dhcl::pvirtVorgbSpeziell(); //α
} // void hhcl::pvirtVorgbSpeziell

// ueberlaedt die Funktion aus kons.cpp
int hhcl::fui0()
{ //ω
	return 0; //α
};
int hhcl::fui1() 
{ //ω
	return 0; //α
};
int hhcl::fui2() 
{ //ω
	return 0; //α
};
void hhcl::fuv0() 
{ //ω
}  //α //ω
// aufgerufen in lauf //α
void hhcl::virtinitopt()
{
	hLog(violetts+"virtinitopt()"+schwarz); //ω
	opn<<new optcl(/*pptr*/&anhl,/*art*/puchar,T_st_k,T_stop_l,/*TxBp*/&Tx,/*Txi*/T_DPROG_anhalten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1); //α //ω
	opn<<new optcl(/*pptr*/&dszahl,/*art*/pdez,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/1); //α //ω
	dhcl::virtinitopt(); //α
} // void hhcl::virtinitopt

// aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	hLog(violetts+Tx[T_virtmacherkl_Tx_lgn]+schwarz+ltoan(Tx.lgn));
//	erkl<<violett<<DPROG<<blau<<Txk[T_tut_dieses_und_jenes]<<schwarz; //ω 
} // void hhcl::pvirtmacherkl //α
//ω
//α

// aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	hLog(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω
	dhcl::virtMusterVorgb(); //α
} // void hhcl::MusterVorgb

// aufgerufen in lauf
void hhcl::pvirtvorzaehler()
{ //ω
} // void hhcl::virtvorzaehler //α
//ω
// aufgerufen in lauf //α
void hhcl::virtzeigversion(const string& ltiffv/*=string()*/)
{
	hLog(violetts+Tx[T_virtzeigversion]+schwarz);
	dhcl::virtzeigversion(ltiffv);  //ω
} // void hhcl::virtzeigversion //α
//ω
//α
// aufgerufen in lauf
void hhcl::pvirtvorrueckfragen()
{
	hLog(violetts+Tx[T_pvirtvorrueckfragen]+schwarz); //ω
} // void hhcl::pvirtvorrueckfragen //α

void hhcl::neurf()
{
	for(auto omit=opn.schl.end();omit!=opn.schl.begin();) {
		omit--;
		if (!(*omit)->Txtrf.empty()) {
			const char* const text=(*omit)->Txtrf.c_str();
			cout<<text<<endl;
		}
	}
} // void hhcl::neurf
 //ω
//α
// aufgerufen in lauf
void hhcl::virtpruefweiteres()
{
	hLog(violetts+Tx[T_virtpruefweiteres]+schwarz); //ω
	if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab])); //α //ω
	hcl::virtpruefweiteres(); // z.Zt. leer //α
} // void hhcl::virtpruefweiteres

// aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{ 
	hLog(violetts+Tx[T_virtzeigueberschrift]+schwarz); //ω
	// hier ggf. noch etwas an 'uebers' anhaengen //α
	hcl::virtzeigueberschrift();
} // void hhcl::virtzeigueberschrift
//ω
//α
// Parameter -st / --stop
// aufgerufen in: main
void hhcl::anhalten()
{
	hLog(violetts+Tx[T_anhalten]+schwarz);
	// crontab
	/*
	setztmpcron();
	for(int iru=0;iru<1;iru++) {
		const string befehl=
			"bash -c 'grep \""+saufr[iru]+"\" -q <(crontab -l)&&{ crontab -l|sed \"/"+zsaufr[iru]+"/d\">"+tmpcron+";crontab "+tmpcron+";};:'";
		systemrueck(befehl,obverb,oblog,*//*rueck=*//*0,*//*obsudc=*//*1);
	} // 	for(int iru=0;iru<2;iru++)
  */
	pruefcron("0"); // soll vor Log(Tx[T_Verwende ... stehen
	fLog(blaus+Tx[T_Cron_Aufruf_von]+schwarz+mpfad+blau+Tx[T_gestoppt]+schwarz,1,oblog); //ω
} // void hhcl::anhalten() //α
//ω
//α
void hhcl::pvirtnachvi()
{ //ω
} //α

// aufgerufen in lauf
void hhcl::pvirtnachrueckfragen()
{
	hLog(violetts+Tx[T_pvirtnachrueckfragen]+schwarz);
	if (rzf) { //ω
	} // 	if (rzf) //α
	// if (initDB()) exit(schluss(10,Tx[T_Datenbank_nicht_initialisierbar_breche_ab]));  //ω
} // void hhcl::pvirtnachrueckfragen //α
//ω
void hhcl::pvirtfuehraus() //α
{ 
	hLog(violetts+Tx[T_pvirtfuehraus]+schwarz); //ω
	const boost::locale::generator gen;
	const std::locale loc{gen("de_DE.UTF-8")};
	setlocale(LC_ALL, "de_DE");
	const size_t aktc(0);
	if (!My) initDB();
	My->usedb(dbq,aktc);
	time_t jetzt{time(0)};
	tm ht({0});
	char rbuf[50],ubuf[50],bisbuf[50];
	memcpy(&ht,gmtime(&jetzt),sizeof ht);
  strftime(rbuf,sizeof rbuf,"%d.%m.%y",&ht);
  strftime(bisbuf,sizeof bisbuf,"%a, %d.%m.%y",&ht);
  strftime(ubuf,sizeof ubuf,"%Y%m%d",&ht);
	const string dname{"/DATA/Patientendokumente/Dienstplanauffaelligkeiten_"+string(rbuf)+".html"};
  mdatei agd(dname,ios::out,0);
	if (agd.is_open()) {
		agd<<"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">"<<endl;
		agd<<"<HTML>"<<endl;
		agd<<"<HEAD>"<<endl;
		agd<<"    <META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=windows-1252\">"<<endl;
		agd<<"    <TITLE></TITLE>"<<endl;
		agd<<"    <META NAME=\"GENERATOR\" CONTENT=\"Dienstplanprogramm\">"<<endl;
		agd<<"    <META NAME=\"CREATED\" CONTENT=\"0;0\">"<<endl;
		agd<<"    <META NAME=\"CHANGEDBY\" CONTENT=\"Gerald Schade\">"<<endl;
		agd<<"    <META NAME=\"CHANGED\" CONTENT=\""<<ubuf<<"\">"<<endl;
		agd<<"    <STYLE TYPE=\"text/css\">"<<endl;
		agd<<"    <!--"<<endl;
		agd<<"        @page { size: 21cm 29.7cm; margin: 2cm }"<<endl;
		agd<<"        P { margin-bottom: 0.21cm }"<<endl;
		agd<<"    -->"<<endl;
		agd<<"    </STYLE>"<<endl;
		agd<<"</HEAD>"<<endl;
		agd<<"<BODY LANG=\"de-DE\" DIR=\"LTR\">"<<endl;
		RS ma(My,"SELECT persnr,kuerzel,nachname,vorname,if(aus=0,'',aus) FROM mitarbeiter WHERE ISNULL(aus) OR aus=0 OR aus>SUBDATE(NOW(),21)",0,ZDB);
		if (ma.obqueryfehler) {
			cout<<"Fehler bei ma: "<<(int)ma.obqueryfehler<<endl;
		} else {
			char ***cerg{0};
			int obkopf{0};
			while (cerg=ma.HolZeile(),cerg?*cerg:0) {
				const string persnr{cjj(cerg,0)};
				int angefangen{0};
				if (strcmp(cjj(cerg,1),"notiz")) {
					for(time_t tag=jetzt-86400*21;tag<jetzt;tag+=86400) {
						memcpy(&ht,gmtime(&tag),sizeof ht);
						strftime(rbuf,sizeof rbuf,"%a, %d.%m.%y",&ht);
						if (!obkopf) {
							agd<<"<PRE><span style='background:#FFCC99'><B>Ausgabe auffaelliger Dienstplaneintraege: </B>"<<rbuf<<" - " <<bisbuf<<endl;
							agd<<"  "<<"Datum  "<<(char)9<<"Vorgb"<<(char)9<<"Dp-Etr"<<(char)9<<"=Std."<<(char)9<<"Z.d.KK-Eintraege"<<(char)9<<"geaendert"<<(char)9<<"</span>"<<endl;
							obkopf=1;
						}
						strftime(ubuf,sizeof ubuf,"%Y%m%d",&ht);
						const string mytag{string(ubuf)};
						string ArtVgb,ArtDp;
						RS wo(My,"SELECT "+string(rbuf).substr(0,2)+" FROM wochenplan WHERE persnr="+persnr+" AND ab<="+mytag+" ORDER BY ab DESC LIMIT 1",0,ZDB);
						if (wo.obqueryfehler) {
							cout<<"Fehler bei wo: "<<(int)wo.obqueryfehler<<endl;
						} else {
							char ***cwo{0};
							if (cwo=wo.HolZeile(),cwo?*cwo:0) {
								ArtVgb=umlweg(cjj(cwo,0));
							}
						} // 					if (wo.obqueryfehler) 
						RS di(My,"SELECT ArtNr FROM dienstplan WHERE tag = "+mytag+" AND persnr="+persnr,0,ZDB);
						if (di.obqueryfehler) {
							cout<<"Fehler bei di: "<<(int)di.obqueryfehler<<endl;
						} else {
							char ***cdi{0};
							if (cdi=di.HolZeile(),cdi?*cdi:0) {
								ArtDp=umlweg(cjj(cdi,0));
								//							agd<<"   "<<rbuf<<": "<<ArtDp<<endl;
							} else {
								ArtDp=ArtVgb;
							}
						} // di.obqueryfehler else
						const int biszahlweg{2}, abzahlda{1};
						int reinz{0},obfalsch{0};
						const double iststd{strtod(ArtDp.c_str(),0)};
						string pid;
////						const string sqlteil{" FROM quelle.eintraege WHERE zeitpunkt BETWEEN "+mytag+" AND ADDDATE("+mytag+",1) AND (art = '"+cjj(cerg,1)+"' OR ((inhalt COLLATE latin1_bin LIKE '%Mitarbeiter: "+cjj(cerg,1)+"%' OR inhalt COLLATE latin1_bin LIKE '% "+cjj(cerg,1)+"' OR inhalt COLLATE latin1_bin LIKE '% ("+cjj(cerg,1)+")') AND NOT inhalt COLLATE latin1_bin LIKE '%mit "+cjj(cerg,1)+"%'))"};
						const string sqlteil{" FROM quelle.eintraege WHERE zeitpunkt BETWEEN "+mytag+" AND ADDDATE("+mytag+",1) AND (art = '"+cjj(cerg,1)+"' OR ((inhalt LIKE '%Mitarbeiter: "+cjj(cerg,1)+"%' OR inhalt LIKE '% "+cjj(cerg,1)+"' OR inhalt LIKE '% ("+cjj(cerg,1)+")') AND NOT inhalt LIKE '%mit "+cjj(cerg,1)+"%'))"};
						const string reints{"SELECT COUNT(0)"+sqlteil};
						RS reint(My,reints,0,ZDB);
						if (reint.obqueryfehler) {
							cout<<"Fehler bei reint: "<<(int)reint.obqueryfehler<<" "<<mysql_error(My->conn[0])<<"Ende"<<endl;
							caus<<reints<<endl;
						} else {
							char ***creint{0};
							if (creint=reint.HolZeile(),creint?*creint:0) {
								reinz=atol(cjj(creint,0)); 
								if (reinz<=biszahlweg && ArtDp!="b" && iststd) {
									obfalsch=1;
								} else if (reinz>=abzahlda && (ArtDp=="b" ||!iststd)) {
									obfalsch=2;
									RS rpid(My,"SELECT REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(GROUP_CONCAT(CONCAT('\\\n         ',LPAD(pat_id,5,' '),' ',DATE_FORMAT(zeitpunkt,'%d.%m.%y %H:%i '),art,' ',inhalt)),'ä','ae'),'ö','oe'),'ü','ue'),'Ä','Ae'),'Ö','Oe'),'Ü','Ue'),'ß','ss') pid "+sqlteil,0,ZDB);
									if (rpid.obqueryfehler) {
										cout<<"Fehler bei rpid: "<<(int)rpid.obqueryfehler<<endl;
									} else {
										char ***cpid{0};
										if (cpid=rpid.HolZeile(),cpid?*cpid:0) {
											pid=(cjj(cpid,0)); 
										}
										//									if (!strcmp(cjj(cerg,1),"mip") && mytag=="20200723") {
										//									agd<<pid<<endl;
										//									caus<<pid<<endl;
										//									}
									}
									//								caus<<"reinz: "<<reinz<<" "<<obfalsch<<endl;
								}
							} // 						if (creint=reint.HolZeile(),creint?*creint:0)
							if (obfalsch) {
								const string Stil{string("style='background:#")+(obfalsch==1?"FF99CC"/*rot*/:"CC99FF"/*lila*/)+"'"};
								string geae;
								RS rgeae(My,"SELECT GROUP_CONCAT(CONCAT(aenddat,': \\\'',artnr,'\\\' (',user,' ',aendpc,')') ORDER BY aenddat DESC SEPARATOR '; ') geae FROM dp.`protok` p WHERE persnr="+persnr+" AND tag= "+mytag,0,ZDB);
								if (rgeae.obqueryfehler) {
									cout<<"Fehler bei rgea: "<<(int)rgeae.obqueryfehler<<" "<<mysql_error(My->conn[0])<<"Ende"<<endl;
								} else {
									char ***cgeae{0};
									if (cgeae=rgeae.HolZeile(),cgeae?*cgeae:0) {
										geae=cjj(cgeae,0);
									}
								}
								if (!angefangen) {
									agd<<endl<<"<span style='background:#FFCC99'><B>"<<umlweg(cjj(cerg,2))<<", "<<umlweg(cjj(cerg,3))<<"</B> ("<<cjj(cerg,1)<<"), Persnr. "<<persnr<<(!cjj(cerg,4)||!*cjj(cerg,4)?"":", Austritt: "+string(cjj(cerg,4)))<<endl;
									angefangen=1;
								} // !angefangen
								agd<<"<span "<<Stil<<">"<<"  "<<rbuf<<(char)9<<ArtVgb<<(char)9<<(ArtVgb==ArtDp?"":ArtDp)<<(char)9<<iststd<<(char)9<<reinz<<(char)9<<geae<<(char)9<<"<span style='background:#E6E6E6'"/*hellgrau*/">"<<pid<<"</span></span>"<<endl;
							} // 							if (obfalsch) 
						} // 					if (reint.obqueryfehler) else
					} // 				for(time_t tag=jetzt-86400*21;tag<jetzt;tag+=86400) 
				} // 				if (strcmp(cjj(cerg,1),"notiz")
			} // 			while (cerg=ma.HolZeile(),cerg?*cerg:0) 
		} // 		if (ma.obqueryfehler) else
		agd<<""<<endl;
		agd<<"   </PRE>"<<endl;
		agd<<"</BODY>"<<endl;
		agd<<"</HTML>"<<endl;
		agd.close();
	}
  systemrueck("chmod 660 '"+dname+"'",obverb,oblog,0,1);
  systemrueck("chown schade:praxis '"+dname+"'",obverb,oblog,0,1);
} // void hhcl::pvirtfuehraus  //α

// aufgerufen in lauf
void hhcl::virtschlussanzeige()
{  
	hLog(violetts+Txk[T_virtschlussanzeige]+schwarz); //ω
	dhcl::virtschlussanzeige(); //α
} // void hhcl::virtschlussanzeige
 
// aufgerufen in: main und pruefcapi
void hhcl::virtautokonfschreib()
{
//// const auto altobverb{obverb}; obverb=1;
	hLog(violetts+Txk[T_autokonfschreib]+schwarz+", "+Txk[T_zu_schreiben]+((rzf||hccd.obzuschreib)?Txk[T_ja]:Txk[T_nein])); //ω
	struct stat kstat{0}; //α
	if (lstat(akonfdt.c_str(),&kstat)) {
		caus<<"Setze obzuschreib, da "<<akonfdt<<" nicht da"<<endl;
		hccd.obzuschreib=1;
	}
	if (rzf||hccd.obzuschreib||kschreib) {
		hLog(gruens+Txk[T_schreibe_Konfiguration]+schwarz);
		// restliche Erklaerungen festlegen
		////    agcnfA.setzbem("language",sprachstr);
		hcl::virtautokonfschreib(); //ω
	} // if (rzf||hccd.obzuschreib) //α
//// obverb=altobverb;
} // void hhcl::virtautokonfschreib

hhcl::~hhcl() 
{ //ω
} // hhcl::~hhcl //α

// wird nur im Fall obhilfe==3 nicht aufgerufen
void hhcl::virtlieskonfein()
{
////	const int altobverb{obverb}; obverb=1;
	hLog(violetts+Txk[T_virtlieskonfein]+schwarz); //ω
	hcl::virtlieskonfein(); //α //ω
	hLog(violetts+Txk[T_Ende]+Txk[T_virtlieskonfein]+schwarz); //α
////	obverb=altobverb;
} // void hhcl::virtlieskonfein() //ω
int main(int argc,char** argv) //α
{
	if (argc>1) { //ω
	} //α
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,pvirtVorgbSpeziell,virtinitopt,parsecl,virtMusterVorgb,virtlieskonfein,verarbeitkonf,virtzeigueberschrift,pvirtmacherkl,virttesterg,zeighilfe,pvirtvorzaehler,lieszaehlerein,dovi,virtzeigversion,pvirtvorrueckfragen,rueckfragen,pvirtnachrueckfragen,pruefggfmehrfach,tuloeschen(logdt...,virtpruefweiteres,pruefcron,pvirtfuehraus,virtautokonfschreib,gitpull,wartaufpids,setzzaehler,schreibzaehler,virtschlussanzeige
	return hhi.retu;
} // int main 

void hhcl::virttesterg()
{
	hLog(violetts+Tx[T_virttesterg]+schwarz);
} //ω
