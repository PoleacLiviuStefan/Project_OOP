#include <iostream>
#include <sstream>
using namespace std;


class Reclama
{

private:

    string platformaReclama;
    double CPC;
    int impact, interactiuni;

public:
    Reclama() : platformaReclama(""), CPC(0.0), impact(0), interactiuni(0) {}
    Reclama(string platformaReclamaI, double CPCI, int impactI, int interactiuniI)
    {
        platformaReclama = platformaReclamaI;
        CPC = CPCI;
        impact = impactI;
        interactiuni = interactiuniI;
    }

    Reclama(const Reclama& r)  //copy constructor
    {
        platformaReclama = r.platformaReclama;
        CPC = r.CPC;
        impact = r.impact;
        interactiuni = r.interactiuni;
    }

    string get_platformaReclama()
    {
        return this->platformaReclama;
    }

    double get_CPC()
    {
        return this->CPC;
    }

    int get_impact()
    {
        return this->impact;
    }

    int get_interactiuni()
    {
        return this->interactiuni;
    }
    void set_platformaReclama(string platformaReclamaI)
    {
        platformaReclama=platformaReclamaI;
    }
    void set_CPC(double CPCI)
    {
        CPC=CPCI;
    }
    void set_impact(int impactI)
    {
        impact=impactI;
    }
    void set_interactiuni(int interactiuniI)
    {
        interactiuni=interactiuniI;
    }
};
istream& operator>>(istream& is, Reclama& r)
{
    string platformaReclamaI;
    double CPCI;
    int impactI, interactiuniI;
    cout<<"------Creare contract------"<<endl;
    cout<<"Platforma pe care se afla reclama(Facebook,Instagram,Tiktok,Google,Youtube): ";
    is >> platformaReclamaI;
    cout<<endl<<"Costul per click: ";
    is >> CPCI;
    cout<<endl<<"Numarul estimativ de oameni care vor vedea reclama: ";
    is >> impactI;
    cout<<endl<<"Numarul estimativ de oameni care o sa interactioneze cu reclama: ";
    is >> interactiuniI;
    cout<<endl;
    r.set_platformaReclama(platformaReclamaI);
    r.set_CPC(CPCI);
    r.set_impact(impactI);
    r.set_interactiuni(interactiuniI);

    return is;
}

class Client
{

private:
    const static int max_serviciiAlese=5;
    string nume;
    string reclameDejaFolosite[6],email,telefon;
    string* serviciuAles;
    bool websiteExistent;
    int capitalReclame,numarReclameDejaFolosite;

public:
    Client(string numeI,string reclameDejaFolositeI[],string emailI,string telefonI,bool websiteExistentI,
           int capitalReclameI,int numarReclameDejaFolositeI)
    {
        nume=numeI;
        for(int i=0; i<numarReclameDejaFolositeI; i++)
            reclameDejaFolosite[i]=reclameDejaFolositeI[i];
        email=emailI;
        telefon=telefonI;
        websiteExistent=websiteExistentI;
        capitalReclame=capitalReclameI;
        serviciuAles = NULL;
        numarReclameDejaFolosite=numarReclameDejaFolositeI;

    }
    //getters
    string get_nume()
    {
        return this->nume;
    }
    string* get_reclameDejaFolosite()
    {
        return reclameDejaFolosite;
    }
    string get_email()
    {
        return this->email;
    }
    string get_telefon()
    {
        return this->telefon;
    }
    string* get_serviciuAles()
    {
        return  serviciuAles;
    }
    bool get_website()
    {
        return this->websiteExistent;
    }
    int get_capitalReclame()
    {
        return this->capitalReclame;
    }
    int get_numarReclameDejaFolosite()
    {
        return this->numarReclameDejaFolosite;
    }
    void set_nume(string numeI)
    {
        nume=numeI;
    }
    void set_reclameDejaFolosite(string reclameDejaFolositeI[],int numarReclameDejaFolositeI)
    {
        numarReclameDejaFolosite=numarReclameDejaFolositeI;
        for(int i=0; i<numarReclameDejaFolositeI; i++)
            reclameDejaFolosite[i]=reclameDejaFolositeI[i];
    }
    string* alegereServiciu(string serviciu,string reclameDejaFolosite[],int numarReclameDejaFolosite,bool websiteExistent);

    ~Client()
    {
        delete[] serviciuAles;
    }
};
string* Client::alegereServiciu(string serviciu,string reclameDejaFolosite[],int numarReclameDejaFolosite,bool websiteExistent)  //alegerea serviciului si apelarea crearii contractului
{
    if (serviciuAles != NULL)
    {
        delete[] serviciuAles;
    }
    serviciuAles = new string[max_serviciiAlese];

    if(serviciu=="Creare Website")
        if(websiteExistent) //conditie ca , clientul sa aibe deja site
        {
            cout<<"Clientul are deja website";
            return NULL;
        }
    for (int i=0; i<numarReclameDejaFolosite; i++)
        if(reclameDejaFolosite[i]==serviciu)
        {
            cout<<"Clientul foloseste deja"<<" "<<reclameDejaFolosite[i];
            return NULL;

        }
    return serviciuAles;

}

//getters reclama



class Website
{

private:
    const static int max_numarFunctionalitati=100;
    int pret,numarPagini,numarFunctionalitati;
    string tipDesign;
    string* functionalitati;
public:
    Website()
    {
        functionalitati = new string[max_numarFunctionalitati];
    };
    //getters website
    int get_pret()
    {
        return pret;
    }
    int get_numarPagini()
    {
        return this->numarPagini;
    }
    int get_numarFunctionalitati()
    {
        return this->numarFunctionalitati;
    }
    string get_tipDesign()
    {
        return tipDesign;
    }
    string* get_functionalitati()
    {
        return functionalitati;
    }

    //setters website
    void set_pret(int pretI)
    {
        pret=pretI;
    }
    void set_numarPagini(int numarPaginiI)
    {
        numarPagini=numarPaginiI;
    }
    void set_numarFunctionalitati(int numarFunctionalitatiI)
    {
        numarFunctionalitati=numarFunctionalitatiI;
    }
    void set_tipDesign(string tipDesignI)
    {
        tipDesign=tipDesignI;
    }
    void set_functionalitati(string functionalitatiI[])
    {
        for (int i=0; i<numarFunctionalitati; i++)
            functionalitati[i]=functionalitatiI[i];
    }
    ~Website()
    {
        delete[] functionalitati;
    }
};



class Echipa
{
private:
    const static int max_numarMembri=10;
    int numarMembri,numarProiecteInLucru;
    string numeMembri[max_numarMembri];

public:
    Echipa(int numarMembriI,string numeMembriI[])
    {
        numarMembri=numarMembriI;
        numarProiecteInLucru=0;
        for(int i=0; i<numarMembriI; i++)
            numeMembri[i]=numeMembriI[i];
    };
    int get_numarMembri()
    {
        return this->numarMembri;
    }
    int get_numarPoriecteInLucru()
    {
        return this->numarProiecteInLucru;
    }
    string* get_membri()
    {
        return numeMembri;
    }
    void set_numarMebri(int nrMembri)
    {
        this->numarMembri=nrMembri;
    }
    void set_adaugaProiecteInLucru()
    {
        this->numarProiecteInLucru+=1;
    }
    void set_membri(string membriNou[],int nrMembri)
    {
        this->numarMembri=nrMembri;
        for (int i=0; i<nrMembri; i++)
            numeMembri[i]=membriNou[i];
    }

};
class Contract
{
private:
    const static int max_numarServicii=50;
    int durataLuni,procentDinIncasari,pretTotal,numarServicii;
    string servicii[max_numarServicii],dataInceperii,dataFinalizarii;
    Echipa* echipa;

public:
    Contract(string serviciiI[],int durataLuniI,int pretTotalI,int procentDinIncasariI,int numarServiciiI,string dataInceperiiI,string dataFinalizariiI,Echipa* echipaI)
    {
        for (int i=0; i<numarServiciiI; i++)
            servicii[i]=serviciiI[i];
        numarServicii=numarServiciiI;
        durataLuni=durataLuniI;
        pretTotal=pretTotalI;
        procentDinIncasari=procentDinIncasariI;
        dataInceperii=dataInceperiiI;
        dataFinalizarii=dataFinalizariiI;
        echipa=echipaI;
    };
    int get_durataLuni()
    {
        return this->durataLuni;
    }

    operator double() const
    {
        return static_cast<double>(procentDinIncasari) / 100.0;
    }
    double get_procentDinIncasari()
    {
        return static_cast<double>(procentDinIncasari) / 100.0;
    }
    int get_pretTotal()
    {
        return this->pretTotal;
    }

    int get_numarServicii()
    {
        return this->numarServicii;
    }
    string get_dataInceperii()
    {
        return dataInceperii;
    }
    string get_dataFinalizarii()
    {
        return dataFinalizarii;
    }

    void set_durataLuni(int durataLuniI)
    {
        durataLuni=durataLuniI;
    }
    void set_procentDinIncasari(double procentDinIncasariI)
    {
        procentDinIncasari=procentDinIncasariI*100;
    }
    void set_pretTotal (int pretTotalI,Client client)
    {
        if(client.get_capitalReclame()<pretTotalI)
            cout<<"Contractul depaseste capitalul pentru reclamei al Clientului";
        else
            pretTotal=pretTotalI;
    }
    void set_numarServicii (int numarServiciiI)
    {
        numarServicii=numarServiciiI;
    }
    void set_dataInceperii (string dataInceperiiI)
    {
        dataInceperii=dataInceperiiI;

    }
    void set_dataFinalizarii (string dataFinalizariiI)
    {
        dataFinalizarii=dataFinalizariiI;
    }
    void set_echipa(Echipa* echipaI)
    {
        echipa=echipaI;
    }

    Contract operator+(const Contract& other) const
    {
        int totalDurata = this->durataLuni + other.durataLuni;
        int totalPret = this->pretTotal + other.pretTotal;
        int totalNumarServicii = this->numarServicii + other.numarServicii;
        double totalProcent = this->procentDinIncasari + other.procentDinIncasari;

        string* totalServicii = new string[max_numarServicii];
        int k = 0;
        for (int i = 0; i < this->numarServicii; i++)
        {
            totalServicii[k++] = this->servicii[i];
        }
        for (int i = 0; i < other.numarServicii; i++)
        {
            totalServicii[k++] = other.servicii[i];
        }

        return Contract(totalServicii, totalDurata, totalPret, totalProcent, totalNumarServicii,"", "",NULL);
    }


};

ostream& operator<<(ostream& out,  Contract& contract) //supraincarcare "<<"
{
    out<< "Durata contractului: "<<contract.get_durataLuni()<<" luni"<<endl;
    out<< "Procentul pe care il ia firma din incasari: "<<contract.get_procentDinIncasari()<<"%"<<endl;
    out<< "Valoarea totala a contractului :" << contract.get_pretTotal()<<endl;
    out<< "Numarul total de servicii pe care le include contractul: " << contract.get_numarServicii()<<endl;
    out<< "Data de incepere a contractului: "<<contract.get_dataInceperii()<<endl;
    out<< "Data de terminare a contractului: " << contract.get_dataFinalizarii()<<endl;
    return out;
}


class Agentie
{
private:
    static const int max_numarContracte=10;
    static const int max_numarServicii=6;
    string nume;
    Reclama* servicii[max_numarServicii];
    int numarServiciiOferite;
    int numarContracteActive;
    Contract* contracteActive[max_numarContracte];
    double incasari;
public:
    Agentie(string numeI)
    {
        nume = numeI;
        numarServiciiOferite = 0;
        numarContracteActive=0;
        incasari=0;

    };
    string get_nume()
    {
        return this->nume;
    }

    int get_numarServicii()
    {
        return this->numarServiciiOferite;
    }
    string get_incasari()
    {
        return to_string(this->incasari) + " Lei";
    }
    int get_numarContracteActive()
    {
        return numarContracteActive;
    }
    void set_nume(string numeNou)
    {
        nume=numeNou;
    }
    void set_numarServiciiOferite(int numarServiciiOferiteI)
    {
        this->numarServiciiOferite=numarServiciiOferiteI;
    }

    void adaugareContract(Contract contract)
    {
        if(numarContracteActive<max_numarContracte)
        {
            numarContracteActive+=1;
            contracteActive[numarContracteActive]=&contract;
            incasari+=contract.get_procentDinIncasari() * contract.get_pretTotal();
        }
        else
            cout<<"ERROR:Agentia are un numar prea mare de contracte active si nu poate face fata";

    }
    void afiseazaContracteActive()
    {
        if(numarContracteActive == 0)
        {
            cout << "Nu exista contracte active la agentia " << endl;
        }
        else
        {
            cout << "Contracte active la agentia " << nume << ":" << endl;
            for(int i = 1; i <= numarContracteActive; i++)
            {
                cout << "Contract " << i << ":" << endl;

                if(contracteActive[i] == nullptr)
                {
                    cout << "Eroare: contractul nu a fost initializat corect" << endl;
                    continue;
                }

                cout << "Pret total: " << contracteActive[i]->get_pretTotal() << " Lei" << endl;
                cout<< "Data inceperii: "<< contracteActive[i]->get_dataInceperii()<< endl;
                cout << "Data incheierii: " << contracteActive[i]->get_dataFinalizarii() << endl;
            }
        }
    }

    void adaugareServiciu(Reclama reclama)
    {

        string platformaReclama=reclama.get_platformaReclama();
        bool ok=true;
        for(int i=1; i<=numarServiciiOferite; i++)
            if(servicii[i]->get_platformaReclama()==platformaReclama)
            {
                servicii[i]=&reclama;
                ok=false;
            }
        if(ok)
        {

            if(numarServiciiOferite<max_numarServicii)
            {
                numarServiciiOferite+=1;

                servicii[numarServiciiOferite]=&reclama;
            }
            else
                cout<<"ERROR:Numarul maxim de servicii este depasit";
        }
    }
    void afisareServicii()
    {
        if(numarServiciiOferite == 0)
        {
            cout << "Nu exista servicii oferite la agentia " << nume << endl;
        }
        else
        {
            cout << "Servicii oferite de agentia " << nume << ":" << endl;
            for(int i = 1; i <= numarServiciiOferite; i++)
            {
                cout << "Serviciu " << i << ":" << endl;
                cout << "Platforma: " << servicii[i]->get_platformaReclama() << endl;
                cout << "Cost per click: " << servicii[i]->get_CPC() << " $" << endl;
                cout << "Impact: " << servicii[i]->get_impact() << endl;
                cout << "Interactiuni: " << servicii[i]->get_interactiuni() << endl;
            }
        }
    }

};



int main()
//lista Reclame="Instagram Ads","Facebook Ads","Google Ads","Creare Website","Youtube Ads"
{
    string reclame[]= {"Instagram Ads","Facebook Ads"};
    Agentie agentie("CreativeAgency");//string numeI
    Client client("FirmaSRL",reclame,"info@firmasrl.com","0753616640",true,300000,2);//string numeI,string reclameDejaFolosite[],string emailI,string telefonI,bool websiteExistentI,int capitalReclameI,int numarReclameDejaFolositeI
    client.alegereServiciu("Youtube Ads",reclame,2,false); //alegereServiciu(string serviciu,string reclameDejaFolosite[],int numarReclameDejaFolosite,bool websiteExistent);
    Reclama reclama1("Facebook",0.20,1200,80);//Creare Reclama //string platformaReclamaI,double CPCI,int impactI,int interactiuniI
    Reclama reclama2("Youtube",0.10,55500,400);
    Reclama reclama3("Instagram",0.12,18000,160);
    Reclama reclama4(reclama1);  //folosire copy constructor
    Reclama reclama5;
    cin>>reclama5;
    agentie.adaugareServiciu(reclama1);
    agentie.adaugareServiciu(reclama2);
    agentie.adaugareServiciu(reclama3);
    agentie.adaugareServiciu(reclama4);
    agentie.adaugareServiciu(reclama5);
    agentie.afisareServicii();
    //Adaugare reclama la agentie
    //string serviciiI[],int durataLuniI,int pretTotalI,int procentDinIncasariI,int numarServiciiI,string dataInceperiiI,string dataFinalizariiI
    string numeMebrii[]= {"Ion","Maria","Andrei"};
    Echipa echipa1(3,numeMebrii);//int numarMembriI,string numeMembriI[]
    Contract contract1(reclame,4,50000,4,1,"02/10/2022","02/12/2022",&echipa1);
    Contract contract2(reclame,4,25000,6,1,"04/01/2023","04/04/2022",&echipa1);
    Contract contract3(reclame,4,34000,7,1,"12/03/2022","12/06/2022",&echipa1);
    contract1.set_echipa(&echipa1);
    agentie.adaugareContract(contract1);
    agentie.adaugareContract(contract2);
    agentie.adaugareContract(contract3);
    cout<<"Numarul de contracte active: "<<agentie.get_numarContracteActive()<<endl;
    agentie.afiseazaContracteActive();

    agentie.set_numarServiciiOferite(3);
    agentie.afisareServicii(); //afiseaza toate serviciile pe care le are agentia
//    agentie.adaugareIncasare(contract1);
//    agentie.adaugareIncasare(contract2);
//    agentie.adaugareIncasare(contract3);
    cout<<agentie.get_incasari()<<endl;


    return 0;
}
