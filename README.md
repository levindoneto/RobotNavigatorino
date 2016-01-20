# RobotNavigatorino
Controle de Navegação do robô Edubot em Arduino.

## Objetivo
Ao longo da escrita do código foi pensado em todas combinações de caminho que o robô poderia andar, fazendo sucessivas verificações de distâncias com a utlização do Sonar.

## Materiais utilizados
Além do Edubot, foi utilizada a IDE do Arduino para fazer a programação do robô.

## Soluções Propostas
Estratégia de navegação:
O robô se move de acordo com um loop que fica fazendo a verificação de distâncias várias vezes ao longo de seu trajeto, onde a distância para ir for maior ele vai, se a distância dos dois lados for igual, ele volta e verifica novamente.

## Resultados obtidos
Ao longo dos testes foram feitas diversas melhorias, como por exemplo a ajuste de verificação de distâncias por onde o robô tem que ir e poder consertar isso;
