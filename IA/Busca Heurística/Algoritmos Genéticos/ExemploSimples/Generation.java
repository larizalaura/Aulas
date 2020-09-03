import java.lang.Math; 

public class Generation {
	private Population currentPop, nextPop;
	private int genNumber;
	private double crossRate;
	private double mutRate;
	private double torRate;
	private int tamPop;
	private int cromSize;


	public Generation() {}

	public Generation(int genNumber, double crossRate, double mutRate, double torRate, int tamPop, int cromSize) {
		this.genNumber = genNumber; //criterio de parada
		this.crossRate = crossRate;
		this.mutRate = mutRate;
		this.torRate = torRate;
		this.tamPop = tamPop;
		this.cromSize = cromSize;
	}



	public void doGeneration() {

		currentPop = new Population(tamPop, cromSize);
		currentPop.createRandomPop();
		currentPop.doFitness();
                
        System.out.print("Geracao: 0 -------");
        currentPop.estatistica();
		
		for (int j = 1; j < genNumber; j++) {
	        System.out.print("Geracao: "+ j + " -------");
		
			currentPop.estatistica();
                        
			int bestIndex = currentPop.getBest(); // seleciono o primeiro melhor
			int secIndex = currentPop.getSecBest(bestIndex);// seleciono o segundo melhor
			

			Individual best1 = new Individual(cromSize);
			Individual best2 = new Individual(cromSize);

			best1 = currentPop.get(bestIndex);
			best2 = currentPop.get(secIndex);

			int i = 2;
			nextPop = new Population(tamPop, cromSize);
			nextPop.setIndividual(0, best1); // adicionamos os dois melhores por
			nextPop.setIndividual(1, best2);

			while (i < tamPop) {
				Individual pai1 = currentPop.torneio(torRate);
				Individual pai2 = currentPop.torneio(torRate);
                                
                double moeda = Math.random();
                if(moeda < crossRate){
                    crossover(pai1, pai2);
                }
				pai1.doMutation(mutRate);
				pai2.doMutation(mutRate);

				nextPop.setIndividual(i, pai1);
				i++;
				nextPop.setIndividual(i, pai2);
				i++;
			}
                        
			currentPop.setPop(nextPop);
            currentPop.doFitness();
            
		}
                
		int bestIndex = currentPop.getBest();
		Individual best1 = new Individual(cromSize);
		best1 = currentPop.get(bestIndex);

		System.out.println(currentPop.toString());
		
		System.out.println("--------Fim da simulacao------------------- \n" + best1.toString() + "\n\n" );

        }

	/*
	 * Two-points crossover operator!
	 */
	private void crossover(Individual pai1, Individual pai2) {
            
		int p1 = (int) (Math.random() * cromSize);
		int p2 = (int) (Math.random() * cromSize);
		int menor = p1;
		int maior = p2;
		Individual backup = new Individual(cromSize);
		backup.setCromossomo(pai1.getCromossomo());

		if (p2 < p1) {
			menor = p2;
			maior = p1;
		}
		//System.out.println("no crossover " + pai1.cromSize);

		for (int i = 0; i < pai1.cromSize; i++) {
			if (i < menor) {
				pai1.setCromossomoValue(pai2.getValue(i), i);
				pai2.setCromossomoValue(backup.getValue(i), i);
			} else if ((i > maior)) {
				pai1.setCromossomoValue(pai2.getValue(i), i);
				pai2.setCromossomoValue(backup.getValue(i), i);
			}
                       
		}
	}

}
