# Fundamentos de Sistemas Ciberfísicos (1º semestre)

Códigos da disciplina **Fundamentos de Sistemas Ciberfísicos** do 1º semestre de Engenharia de Software (PUCPR): os primeiros programas em C e os projetos com Arduino, incluindo o TDE final **VagaCerta**.

```
aula01/                  primeiro programa em C
TDE-final-VagaCerta/     TDE final: sistema de vagas de estacionamento
arduino/sketch_apr27a/   display de 7 segmentos
arduino/sketch_jun22a/   cópia de desenvolvimento do VagaCerta
```

---

## VagaCerta: TDE final (`TDE-final-VagaCerta/`)

Sistema que mostra se as vagas de um estacionamento estão **livres ou ocupadas** e quantas vagas livres existem. Feito pelo "Grupo da Pizza" e simulado no Tinkercad (o link está em `Link-tinkercad.txt`).

### Componentes

| Componente | Função | Pinos do Arduino |
|---|---|---|
| Sensor ultrassônico da vaga 1 | Detecta se há um carro na vaga 1 | Trigger 12, Echo 11 |
| Sensor ultrassônico da vaga 2 | Detecta se há um carro na vaga 2 | Trigger 8, Echo 9 |
| LEDs da vaga 1 | Vermelho = ocupada, verde = livre | Vermelho 13, verde 10 |
| LEDs da vaga 2 | Vermelho = ocupada, verde = livre | Vermelho 7, verde 6 |
| Display LCD 16x2 I2C | Mostra o nome do grupo e o número de vagas livres | SDA A4, SCL A5 |

### Como o código funciona

- **Bibliotecas:** `LiquidCrystal_I2C` e `Wire` para o display e `NewPing` para os sensores ultrassônicos
- **`setup()`:** configura os pinos dos LEDs como saída, liga o display e faz uma animação de abertura: as letras de "Grupo" entram deslizando pela tela, depois aparece "Grupo da Pizza" e o texto "VAGA CERTA" pisca algumas vezes
- **`loop()`:** a cada ciclo, mede a distância em cada sensor com `ping_cm()`, com alcance máximo de 20 cm:
  - se o sensor detecta algo, a vaga está **ocupada**: acende o LED vermelho e apaga o verde
  - se não detecta nada, a vaga está **livre**: acende o LED verde e soma 1 no contador de vagas
  - no fim, escreve "VAGAS LIVRES: X" na segunda linha do display

> **Atenção:** na linha `digitalWrite(13, 0); o` sobrou um `o` depois do ponto e vírgula. É só apagar esse `o` para o código compilar na IDE do Arduino.

### Como rodar

1. Instale as bibliotecas **LiquidCrystal I2C** e **NewPing** na IDE do Arduino
2. Abra `VagaCerta.ino`, selecione a placa (Arduino Uno) e faça o upload
3. Ou abra o link do Tinkercad para ver a simulação do circuito

---

## Aula 01: primeiro programa em C (`aula01/aula01.c`)

Programa que lê dois números inteiros (`a` e `b`), calcula a soma e a média e mostra os resultados com `printf`. É o primeiro contato com variáveis, tipos (`int`, `signed char`, `float`), `scanf` e `printf` em C.

```bash
gcc aula01/aula01.c -o aula01
./aula01
```

---

## Sketches Arduino (`arduino/`)

- **`sketch_apr27a`: display de 7 segmentos (cátodo comum).** Define um pino do Arduino para cada segmento (de `a` até `g`) e acende os segmentos `a`, `b`, `c`, `d` e `g` para formar o número **3** no display.
- **`sketch_jun22a`:** cópia do código do VagaCerta, usada durante o desenvolvimento do TDE final.
