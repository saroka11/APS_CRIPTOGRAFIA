### **ATIVIDADE SUPERVISIONADA: ABORDA O TEMA CRIPTOGRAFIA UTILIZANDO TÉCNICAS DE ÁLGEBRA LINEAR**


Este projeto implementa a criptografia e descriptografia de palavras usando técnicas de álgebra linear em linguagem C. O programa é dividido em dois módulos:


### **Modulo 1:** criptografia.

O programa recebe uma palavra do usuário, de até 6 letras, e coloca a palavra como elementos de uma Matriz 3x2 na ordem ilustrada abaixo.  
  
Depois faz a substituição de cada letra pelo número indicado na tabela de conversão, criando assim uma nova matriz númerica.  


`Tabela de Conversão e formato que a matriz3x2 deve ficar:`

![tabela](https://github.com/saroka11/APS_CRIPTOGRAFIA/assets/138390112/e22f95e4-ef82-42ec-9555-586d4bddde4f)

  
No final será feita a multiplicação entre a Matriz númerica 3x2 com a matriz de criptografia C 3x3, retornando a matriz criptografada. `( matriz C = {1, 0, 1, 1, 1, 1, 0, 2, -1} )`.  


Exemplos:

Palavra de entrada: Brasil  
Resultado da Matriz criptografada: { 3, 31, 21, 40, 35, 6 }


Palavra de entrada: Lista  
Resultado da Matriz criptografada: { 31, 20, 40, 21, -1, 2 }   

### **Módulo 2**: nesse módulo será feita a descriptografia.   
O programa recebe uma matriz 3x2 criptografada e inverte o processo de criptografia para recuperar a palavra original.    
  
O processo é feito multiplicando a matriz inversa de C (a matriz de criptografia) pela matriz criptografada informada pelo usuário, no final resultando na matriz da mensagem original.


    
Exemplos:   

Matriz = { 3, 31, 21, 40, 35, 6 }  
Palavra original: Brasil  

Matriz = { 36, 22, 61, 37, 30, 16}  
Palavra original: Python
