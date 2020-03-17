------ PROJETO PPM ------



O que foi feito:
	

	O modo como foram pensados os pontos na imagem pode ter sido diferente do que normalmente se vê. Isso porque os pontos inseridos pelo usuário serão dispostos na imagem final tendo como base um plano cartesiano X por Y, ao invés de serem exibidos de acordo com a forma como as matrizes em C se organizam espacialmente. Assim, caso o ponto (0, 0) seja inserido como parâmetro para pintar, ele aparecerá no canto inferior esquerdo da imagem.

	Foram implementadas todas as funções obrigatórias:
		
		image: Iniciar a imagem com as dimensões especificadas (X e Y respectivamente);
	
			Ex: image 600 800	
		clear: Limpar a tela com a cor (em RGB) inserida;
	
			Ex: clear 0 0 0	
		color: Escolher a cor (em RGB) atual para desenho;
	
			Ex: color 212 40 165	
		line: Desenhar uma reta de um ponto a outro [Ponto 1 (X, Y) e ponto 2 (X, Y)];
	
			Ex: line 200 100 400 500	
		polygon: Desenha um polígono com vértices nos pontos inseridos [Número de vértices seguido dos pontos];
			Ex: polygon 3 100 200 300 400
 50 60		
		circle: Desenha um círculo com determinado centro e raio [Ponto central (X, Y) e raio];
			Ex: circle 100 200 25
		
		fill: Preenche a partir de um ponto inserido [Ponto (X, Y)];

			Ex: fill 300 200		
		save: Salva o desenho em um arquivo ppm [NomeDoArquivo.ppm];
			Ex: save reprovei.ppm
	



O que não foi feito:
	
	Não foram implementados recursos extras no projeto.
	
	Não foi implementada a função "rect", que desenha retângulos.



O que teria sido feito diferentemente:
	
	A forma como a matriz de pixels foi definida foi feita de acordo com o que eu pensei que seria mais lógico fazer. Ao invés disso, deveria ter consultado o "cliente" para saber o que era esperado que fosse mostrado após a inserção dos comandos. Me refiro ao comentado anteriormente, com relação à impressão da imagem.
 Uma melhor modularização das funções e bibliotecas, acredito que algumas tenham ficado sobrecarregadas e com excessos de parâmetros. Isso fez com que a função "fill" possa ser ineficiente em preenchimentos muito grandes.



Execução:
	
	O arquivo de entrada deve estar junto ao main.exe e nomeado "entrada.txt".
	
	O arquivo Makefile já contém o parâmetro "-lm"	para compilação da biblioteca matemática, a única que necessita dessa especificidade.
	Compilado utilizando o gcc 9.2.1.
	


Modularização:
	
	- main.c = rege o código, fazendo as repetições e chamando as funções de acordo com um condicional switch que processa as primeiras letras dos comandos inseridos
	
	- leitura.h = define as funções para recebimento das informações inseridas pelo usuário.
	
	- desenho.h = define as structs ponto, cor e pixel (cor + pixel), além das funções para pintar, desenhar e preencher.
	
	- retas.h = define as funções de desenho retilíneo ("sub-biblioteca" da desenho.h, dado que é apenas uma separação para melhor leitura e manutenção).



-------------------------
