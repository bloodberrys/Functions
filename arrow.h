	
void arrowKatalog(int realPosition, int arrowPosition){

	if(realPosition == arrowPosition){
		printf("[%lc]",(wint_t)251);
	}
	else{
		printf("[ ]");
	}
}	
	
	
void arrowHere(int realPosition, int arrowPosition){

	if(realPosition == arrowPosition){
		printf("        -> ");
	}
	else{
		printf("           ");
	}
}	
	
