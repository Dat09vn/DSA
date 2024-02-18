codePro.lge:
  
1. Settlement for Sponsorship
void Solve2()
{
	int sum = 0;
	int sum_max = 0;
	int element_max = D[0];
	
	for(int i = 0; i < N; i++) {
		sum += D[i];
		element_max = max(element_max, D[i]);
		if(sum <= 0) sum = 0;
		sum_max = max(sum_max, sum);
	}
	
	if(sum_max == 0) {
		sol = element_max;
	}
	else {
		sol = sum_max;
	}
}
