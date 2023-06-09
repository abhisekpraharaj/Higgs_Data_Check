void inspectionsg(){
TFile *f1= new TFile("Higgs_signal.root","READ");
TList *keys= f1->GetListOfKeys();
TIter nextKey(keys);
TKey *key;
while((key=dynamic_cast<TKey*>(nextKey()))){
	const char *keyname = key->GetName();
	const char *classname = key->GetClassName();
printf("Key:%s, Classname:%s\n", keyname, classname);

if(TString(classname)=="TTree"){
	TTree *tree = dynamic_cast<TTree*>(key->ReadObj());
	}
	
delete key;
}
f1->Close();
}
//this code is to check the data is availble inside a .root file or not and tben using this code we can read tbe root file easily.
//Written by abhisek praharaj.

