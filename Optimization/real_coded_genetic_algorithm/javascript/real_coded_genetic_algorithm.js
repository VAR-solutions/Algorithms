/*
	Real Coded Genetic Algorithm:

	Attempts to minimize the objective function fobj applying genetic algorithm where:
		fobj: Function to be minimized
		xSize: Amount of variables necessary to compute fobj
		xRange: Range from which each variable on the first population will be generated
		populationSize: Amount of individuals in each generation
		selectedParentsAmount: Amount of best parents that will be chosen to pass on to the next generation
		mutationProbability: Probability that one of the child's genes will be mutated
		mutationLength: Lenght of the noise that will be added to mutated gene
		maxGenerations: Amount of generations that will be computed until best individual is returned
*/


//Generates random population
function generateStartPopulation(xSize, xRange, populationSize)
{
	let population = [];

	for(let i=0; i<populationSize; i++)
	{
		population[i] = [];
		for(let j=0; j<xSize; j++) population[i][j] = xRange[0] + Math.random()*(xRange[1]-xRange[0]);
	}

	return population;
}

//Auxiliary function for sort()
function compareNumbers(a, b) 
{
  	return a - b;
}

//Atributes to each individual a ranking, 0 being best individual and (populationSize-1) beingg worst
function rankPopulation(fobjResult)
{
	let fitness = [];
	let sortedFobjResult = []

	for(let i in fobjResult) sortedFobjResult[i] = fobjResult[i];
	sortedFobjResult.sort(compareNumbers);
	
	for(let i in sortedFobjResult)
	{
		let j = 0;
		while(sortedFobjResult[i] != fobjResult[j] || fitness[j] != undefined) j++;
		fitness[j] = i;
	}

	return fitness;
}

//Returns a probability vector that makes more likely for better individuals to be chosen as parents
function makeProbabilityVectorOutOfFitness(fitness, populationSize)
{
	let counter = 0;
	let vector = [];

	for(let i in fitness)
	{
		for(let j=0; j<(populationSize - fitness[i]); j++)
		{
			vector[counter] = i;
			counter++;
		}
	}

	return vector
}

//Choses a parent drawing a random index from probabilityVector
function chooseParent(probabilityVector)
{
	let drawnIndex = Math.floor(probabilityVector.length * Math.random());
	return probabilityVector[drawnIndex];
}

//From the two chosen parents generates a child by linearly combinin each gene and applying mutation whenever the probability is met
function breedChild(population, parentIndex1, parentIndex2, mutationProbability, mutationLength)
{
	let child = [];

	for(let i in population[parentIndex1])
	{
		let lambda = Math.random();
		child[i] = population[parentIndex1][i]*lambda + population[parentIndex2][i]*(1-lambda);
	}

	let drawnMutation = Math.random();
	if(drawnMutation <= mutationProbability)
	{
		let mutatedGene = Math.floor(population[parentIndex1].length * Math.random());
		child[mutatedGene] += mutationLength*(Math.random()-0.5);
	}

	return child;
}


//Description on begin of file
function realCodedGeneticAlgorithm(fobj, xSize, xRange, populationSize = 16, selectedParentsAmount = 4, mutationProbability = 0.05, mutationLength = 0.05, maxGenerations = 100)
{
	let population = generateStartPopulation(xSize, xRange, populationSize);
	let fobjResult = [];
	let fitness;

	for(let i in population) fobjResult[i] = undefined;

	for(let gen=0; gen<maxGenerations; gen++)
	{
		for(let i in population) if(fobjResult[i] == undefined) fobjResult[i] = fobj(population[i]);
		fitness = rankPopulation(fobjResult);

		for(let i in population)
		{
			if(fitness[i] >= selectedParentsAmount)
			{
				let probabilityVector = makeProbabilityVectorOutOfFitness(fitness, populationSize)
				let parentIndex1 = chooseParent(probabilityVector);
				let parentIndex2 = chooseParent(probabilityVector);
				population[i] = breedChild(population, parentIndex1, parentIndex2, mutationProbability, mutationLength);
				fobjResult[i] = undefined;
			}
		}
	}

	let bestIndividualIndex;
	for(let i in population) if(fitness[i] == 0) bestIndividualIndex = i;

	let bestIndividual = 
	{
		genes: population[bestIndividualIndex],
		value: fobjResult[bestIndividualIndex]
	}

	return bestIndividual;
}


//Test function, only one local minimum
function f1(x)
{
	//Global minimum at [0, 0]
	return x[0]*x[0] + x[1]*x[1]; 
}


//Another test function, multiple local minima
function f2(x)
{
	//Global minimun at [1.6288, 1.6288]
	return -(x[0]*Math.sin(4*Math.PI*x[0]) - x[1]*Math.sin(4*Math.PI*x[1] + Math.PI) + 1)
}

//Execution of test functions
console.log(realCodedGeneticAlgorithm(f1, 2, [-10, 10]))
console.log(realCodedGeneticAlgorithm(f2, 2, [1, 2]))