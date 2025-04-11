#  Métodos Numéricos: Bisseção e Secante

Este projeto implementa dois métodos numéricos clássicos para encontrar raízes de funções reais: **Bisseção** e **Secante**.

##  Objetivo

Fornecer uma ferramenta em C para calcular raízes de equações não lineares, aplicando os métodos de Bisseção e Secante em diferentes funções matemáticas.

---

## 📁 Estrutura do Código

O código principal está no arquivo `main.c` e inclui as seguintes partes:

- Definição de funções matemáticas:
  - `f1(x) = x^5 − 2x^4 − 9x^3 + 22x^2 + 4x − 24`
  - `f2(x) = sqrt(x) - cos(x)`
  - `f3(x) = (sqrt(x) - 5) * exp(-x)`
  - Exemplo adicional: `x² - 2`
  
    - Você pode facilmente trocar a função alvo alterando a linha abaixo no main():
    ```c
      double (*f)(double) = f3; // Mude para f1, f2 ou exemplo
    ```
- Implementação dos métodos:
  - `bissecao()` – Método da Bisseção
  - `secante()` – Método da Secante
- Estimativa da derivada com diferenças finitas
- Interface por linha de comando

---

## ⚙️ Como Compilar

Compile o código com um compilador C como `gcc`:

```bash
gcc -o raiz main.c -lm
```
---

## ▶️ Como Executar

```bash
gcc -o raiz main.c -lm
```
- `bs` → usa o método da bisseção
- `sec` → usa o método da secante
- `eps` → critério de parada (erro)
- `x0, x1` → valores iniciais (intervalo ou aproximações)

---

## Exemplo de Saída
```css
Metodo: bs
Refinamento e criterio de parada: 1e-06
Error maximo 1.0E-06
x(0) ou a = 0.00000000000000000000
x(1) ou b = 5.00000000000000000000

*** Metodo da Bissecao ***
Error: 1.00000000e-06
Intervalo: (0.000000, 5.000000)
fx(a = 0.000000000000000) = -5.000000000000000
fx(b = 5.000000000000000) = 0.080483742049970

Informacao da derivada:
gx(a = 0.000000000000000) = 45.000000000000000
gx(b = 5.000000000000000) = -5.683150999999999

TEM RAIZ REAL <-**********
Valor de x e 4.999989986419678 - passos de iteracao 20
```
