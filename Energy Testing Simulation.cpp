#include <stdio.h> 

float simulasienergy(float, float, float);

int main()
{
	char nama_karakter[100];
	float burst_cost;
	float ER;
	float particle;
	float result;
	float cooldownskill;
	
	puts("Program Simulasi Energy Testing On-field Character");
	puts("===========================================================================================");
	puts("Konstelasi dan Efek samping lainnya tidak dapat dihitung dalam program ini");
	puts("Hanya Pure Total ER% yang berasal dari artifact dan senjata yang digunakan");
	puts("Untuk efek samping dan konstelasi silahkan hitung sendiri dan digabung dengan total ER%");
	puts("Misalkan : C2 Bennett memiliki 30% ER tambahan, maka ER Total + 30% ");
	puts("Untuk Particle dasar karakter, hanya dapat input salah satu saja");
	puts("Misalkan : Bennett memiliki particle dasar 2-3 particle, maka dapat input 2 atau 3");
	puts("Created by : Xenoids");
	puts("===========================================================================================");
	
	printf("Input nama karakter :\n");
	printf(">>");
	scanf("%[^\n]",nama_karakter);
	
	printf("Input burst cost %s : \n",nama_karakter);
	printf(">>");
	scanf("%f",&burst_cost);
	getchar();
	
	printf("Input ER %s tanpa %%, untuk koma gunakan (.) : \n",nama_karakter);
	printf(">>");
	scanf("%f",&ER);
	getchar();
	
	ER = ER * 0.01;
	
	//Debug Purpose
	//printf("ini ER : %.2f\n",ER);
	
	printf("Input jumlah particle dasar yang dapat dihasilkan %s per elemental skill : \n",nama_karakter);
	printf(">>");
	scanf("%f",&particle);
	getchar();
	
	printf("Input cooldown elemental skill %s : \n",nama_karakter);
	printf(">>");
	scanf("%f",&cooldownskill);
	getchar();
	puts("");
	
	
	result = simulasienergy(particle, ER,burst_cost);
	
	cooldownskill = result * cooldownskill;
	printf("----------------------------------------------------------------\n");
	printf("Elemental Skill yang akan digunakan sebanyak :%.f kali \n",result);
	printf("Total Cooldown Elemental Skill : %.f detik\n",cooldownskill);
	printf("----------------------------------------------------------------\n");
	
	printf("Terima kasih telah mencoba Program Simulasi Energy Testing On-field Character\n");
	return 0;
}

float simulasienergy(float particle, float ER,float burst_cost)
{
	float ElementalSkill_Count = 0;
	float particle_penampung = 0;
	float totalenergy;
	
	
	while(totalenergy < burst_cost)
	{
		ElementalSkill_Count++;
		particle_penampung+= particle;
		
		// Debug purpose
		//printf("ini particle penampung : %.2f\n",particle_penampung);
		totalenergy = particle_penampung * 3 * ER;
		
		// Debug purpose
		//printf("ini total energy sekarang : %.2f\n",totalenergy);
	}
	
	return ElementalSkill_Count;
}

