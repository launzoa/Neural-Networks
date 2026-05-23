# Projeto Algorítmico do Perceptron: Decisões Arquiteturais e Teoria

Este documento traça o modelo mental, o fluxo de projeto e as decisões teóricas tomadas durante a construção de um algoritmo de Rede Neural Artificial: o Perceptron Clássico de única camada. O objetivo desta documentação é servir como registro do raciocínio lógico e algorítmico, abstraindo as minúcias de linguagens de programação e focando no fluxo de dados e no modelo matemático.

---

## 1. A Arquitetura Base (Separação Lógica)
**1. O Objetivo:** 
Criar a fundação estrutural da rede evitando que a matemática do processamento de dados ficasse atrelada de forma caótica aos controladores de laços temporais (épocas).

**2. A Primeira Decisão (Arquitetura):** 
O modelo teórico foi ramificado em duas entidades lógicas distintas: O **Neurônio** (a unidade estrita de processamento geométrico/matemático) e o **Orquestrador** (a estrutura da "Rede", que gerencia o fluxo de tempo e de aprendizado).

**3. Estrutura Detalhada (How-To):**
- A entidade **Neurônio** detém as propriedades vetoriais ($Pesos$) e o escalar ($Viés$). Seus únicos comportamentos são: efetuar o Produto Escalar entre os dados de entrada e seus pesos, somar o viés para gerar o estado de ativação ($U$), e aplicar uma Função de Ativação que converta o resultado bruto em um sinal binário legível ($0$ ou $1$).
- A entidade **Orquestrador** detém os "hiperparâmetros" macro da rede (como a Taxa de Aprendizado $\eta$) e atua como uma interface de fachada para gerir o processo de ponta a ponta.

**4. Conexão das Partes:** 
O Orquestrador capta as amostras do ambiente externo e as delega ao Neurônio. O Neurônio responde com a inferência bruta, e o Orquestrador usa essa resposta para determinar os passos seguintes da lógica de treinamento.

**5. Aplicação Prática:** 
Essa abstração permite que o conceito de "Unidade Neural" possa ser reutilizado no futuro, empacotando o cálculo matricial numa caixa preta que age de modo indiferente ao tipo de matriz de dados que o Orquestrador entrega a ele.

---

## 2. A Matemática do Encapsulamento
**1. O Objetivo:** 
Garantir a integridade da equação e do estado interno da unidade neural, impedindo que os pesos que determinam a Reta de Decisão sejam corrompidos por estímulos incorretos da rede principal.

**2. A Segunda Decisão (Encapsulamento Teórico):** 
As matrizes de conhecimento ($Pesos$ e $Viés$) são inatingíveis externamente. Para aprender, a unidade deve atualizar seus próprios parâmetros ativando seu mecanismo intrínseco de plasticidade neural, guiado pela Regra Delta.

**3. Estrutura Detalhada (How-To):**
- A unidade neural não permite que a Reta seja forçada. No lugar disso, ela requer dois insumos: o Grau de Erro da rede ($Erro$) e o Vetor de Dados ($Entrada$).
- Ao ativar seu comportamento de plasticidade (o método de *Learning*), o neurônio aplica a álgebra para cada dimensão: $Peso_{novo} = Peso_{atual} + \eta \cdot Erro \cdot Entrada$.

**4. Conexão das Partes:** 
Quando uma época está correndo, o Orquestrador simplesmente envia a "força de correção" calculada. A tarefa de escalar as coordenadas e mover de fato os eixos espaciais recai matematicamente e inteiramente sobre o próprio neurônio.

**5. Aplicação Prática:** 
Este princípio espelha fielmente o conceito biológico de sinapse, onde o próprio ponto focal se regula, tornando as abstrações do software robustas contra falhas de lógica do fluxo global de treinamento.

---

## 3. Limitação de Escopo Lógico (Princípio YAGNI)
**1. O Objetivo:** 
Produzir o fluxo mais cristalino possível do Perceptron original proposto por Frank Rosenblatt (1958), sem inflar o diagrama algorítmico com abstrações desenhadas para redes profundas modernas.

**2. A Decisão (Limite de Abstração):** 
Mantivemos o algoritmo linear e absoluto. Decidimos não preparar a infraestrutura para funções contínuas diferenciáveis e cadeias de propagação reversa de erro em camadas ocultas.

**3. Estrutura Detalhada (How-To):**
- Foi adotada a Função Degrau (Heaviside Step Function) como função de ativação, que entrega saídas inflexivelmente não-lineares e polarizadas ($0$ ou $1$).
- A propagação da correção recebe diretamente o erro absoluto ($Gabarito_{esperado} - Saída_{gerada}$), sem o intermédio de derivadas complexas.

**4. Conexão das Partes:** 
Graças à adoção desse escopo minimalista, quando o Orquestrador identifica a falha, o erro volta imediatamente e integralmente na mesma linha do tempo em que o Neurônio realizou a tentativa.

**5. Aplicação Prática:** 
Essa decisão enxugou o fluxograma do projeto, consolidando-o como um excelente material de introdução sobre como redes geométricas desenham fronteiras simples em espaços linearmente separáveis (como as portas lógicas AND/OR).

---

## 4. A Malha de Treinamento e Convergência
**1. O Objetivo:** 
Projetar as engrenagens iterativas para que o hiperplano de decisão consiga "navegar" gradativamente pelo espaço até encontrar a fronteira perfeita que separa as classes.

**2. A Decisão (O Fluxo de Aprendizado Online):** 
O modelo de treinamento adotado seguiu o fluxo analítico de *Stochastic Gradient Descent (SGD)* ou *Aprendizado Online*. Os reajustes acontecem independentes, não acumulados.

**3. Estrutura Detalhada (How-To):**
- O fluxo de dados opera recebendo um Gabarito (Saída) e uma Matriz de Amostras de tamanho $N$ (onde cada amostra é um vetor).
- Dois grandes laços de repetição governam a teoria:
  - O **Laço Maior (Épocas):** Responsável por reiterar o Dataset sobre o modelo para compensar os pequenos incrementos da Taxa de Aprendizado.
  - O **Laço Menor (Amostras):** Onde o treinamento real da Reta toma forma, amostra a amostra individualmente.

**4. Conexão das Partes:** 
Diferente de sistemas agrupados (*batch*), neste cenário, tão logo o neurônio preveja a linha `i` da matriz $X$, o Orquestrador quantifica a distância do alvo e engatilha a plásticidade neural se necessário. O estado analítico do modelo já foi geometricamente alterado quando a linha `i+1` for lida no segundo seguinte.

**5. Aplicação Prática:** 
Esse comportamento dinâmico permite à reta "dançar" pelo espaço bidimensional ou tridimensional durante as épocas até aterrissar em um local geométrico em que nenhum erro seja gerado, alcançando a Convergência.

---

## 5. O Ponto Embrionário (Estocasticidade)
**1. O Objetivo:** 
Ditar o estado inicial dos vetores do modelo antes do relógio computacional iniciar, garantindo que as primeiras derivações da reta de decisão sejam fluidas e matemáticas.

**2. A Decisão (Ruído Numérico Inicial):** 
O algoritmo dita que a Matriz de Pesos e o Viés não sejam populados aleatoriamente em escala irrestrita, tampouco apenas com a ausência do sinal (zeros absolutos). Eles recebem um ruído aleatório em uma faixa decimal normalizada minúscula.

**3. Estrutura Detalhada (How-To):**
- Antes de qualquer inferência de dados ocorrer, aplica-se uma distribuição uniforme restrita para popular as dimensões, geralmente variando na modesta faixa de $[-1.0, 1.0]$.

**4. Conexão das Partes:** 
O benefício analítico recai sobre a primeira inferência cruzada que o neurônio for realizar. Ao confrontar o vetor de entrada original pelos vetores da rede, a multiplicação garantirá que a "soma inicial não-treinada" resultante flutue perto da origem do plano.

**5. Aplicação Prática:** 
Se inicializássemos a rede teoricamente com números monumentais, os reajustes da Constante de Aprendizado seriam nulos comparados à magnitude da fronteira atual, inviabilizando a convergência num tempo hábil. Iniciar de forma modesta permite que o gradiente esculpe as retas rapidamente com altíssima precisão.
