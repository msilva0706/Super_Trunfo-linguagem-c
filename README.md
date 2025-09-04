# 🃏 Super Trunfo em C

Este é um projeto em C que simula uma versão simplificada do jogo **Super Trunfo**, utilizando países como cartas.  
O jogador escolhe duas cartas e dois atributos para comparar. O vencedor é definido pela soma dos atributos escolhidos.

---

## 🚀 Funcionalidades

- Estrutura de dados com `struct` para representar cartas.  
- 4 cartas iniciais pré-cadastradas: **Brasil, Japão, EUA, França**.  
- Cálculo automático de **densidade demográfica**.  
- Comparação de **2 atributos escolhidos pelo jogador**.  
- Definição de vencedor com base na soma dos atributos.  
- Exibição detalhada do resultado da rodada.

---

## 📖 Como funciona

1. O programa exibe uma lista de cartas disponíveis.  
2. O jogador escolhe **duas cartas diferentes**.  
3. O jogador escolhe **dois atributos** para comparar:  
   - População  
   - Área  
   - PIB  
   - Pontos Turísticos  
   - Densidade Demográfica (menor valor vence)  
4. O programa compara os atributos e mostra:  
   - Vencedor de cada atributo.  
   - Soma dos atributos.  
   - Vencedor final da rodada.

---

## 🛠️ Tecnologias

- Linguagem **C**
- IDE recomendada: [Code::Blocks](https://www.codeblocks.org/) ou [Eclipse CDT](https://www.eclipse.org/cdt/)  
- Compilador: **GCC**

---

## ▶️ Como executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/super-trunfo-c.git
   cd super-trunfo-c
   ```

2. Compile o código (via terminal):
   ```bash
   gcc src/main.c -o super_trunfo
   ```

3. Execute o programa:
   ```bash
   ./super_trunfo
   ```

Ou simplesmente abra o projeto no **Code::Blocks**, cole o código no `main.c` e pressione `F9`.

---

## ✨ Melhorias futuras

- Adicionar mais cartas de países.  
- Criar modo automático (computador vs jogador).  
- Implementar sistema de rodadas.  
- Interface gráfica simples (usando GTK ou ncurses).  

---

👨‍💻 Desenvolvido em C como exercício de lógica de programação e estruturas de dados.
