int ContaOperazioni(int N,int K, int* secchi){
	// la seguente operazione restituisce 102 come risultato
    int mancanti=0, eccesso=0;
    for (int i=0; i<N; i++){
        if (secchi[i]>K) eccesso+=secchi[i]-K;
        if (secchi[i]<K) mancanti+=K-secchi[i];
    }
    int ris=eccesso;
    if (mancanti>eccesso) ris+=mancanti-eccesso;
	return ris;
}
