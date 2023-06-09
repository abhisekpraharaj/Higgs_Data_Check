void inspectionbg()
{
TFile *f1 = new TFile("Higgs_background.root", "READ");
TList *keys = f1->GetListOfKeys();
TIter nextKey(keys);
TKey *key;
while((key=dynamic_cast<TKey*>(nextKey()))){
	const char * keyname = key->GetName();
	const char * classname = key->GetClassName();

printf("Key: %s, Class: %s\n", keyname, classname);

if(TString(classname)=="TTree"){
	TTree* tree = dynamic_cast<TTree*>(key->ReadObj());
	}
	

delete key;
}
f1->Close();
}

