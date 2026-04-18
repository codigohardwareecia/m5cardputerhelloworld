
Esse aqui e o cardputer, um carinha muito versatiol, tambem da familia ESP, mas com caracteristicas de um mini computador, vem quase tudo nele.

Nesse video vamos ver como gravar firmwares predefinidos usando o M5Burner, bem como implementar um projetinho bem bacana para enviarmos o audio do PC para o M5Cardputer, nosso objetivo principal e desvendar a comunicação via Wifi usando o UDP.

Primeira vamos acessar o Google e no campo de pesquisa digite M5Burner

Clique no primeiro link M5Burner-docs ou acesse a URL na descrição
https://docs.m5stack.com/en/uiflow/m5burner/intro

Agora clique no link de download logo a frente M5Burner_Windows 

Apos o download descompacte o arquivo ZIp M5Burner-v3-beta-win-x64

Dentro da pasta descompactada acesse M5Burner.exe

Conecte o cabo USB ao M5Cardputer

No menu da esquerda Device Type seleciona Cardputer, os firmwares suportados serão listadaos

Importante salientar que existe os Firmwares Oficiais e não oficiais

Selecione o firmware desejado, e clique em Download, depois clique em Burn

Em seguida vai ser aberto uma caixa de diaogo perguntado a porta e a velocidade de comunicação, mantenha o sugerido e clique em Burn, pode dar algumas mensagesns de advertencia mas ignore neste momento.

Depois de concluido clique em Brun sucessfully.

Vc pode escolher o firmware que desejar.

Tem até o Doom.

Agora vamos fazer um Hello Wolrd no Arduino

#### Configuração

Vá em File > Preferences > Aditional Board Manager URL e clique no icone ao lado

Cole a url abaixo e depois clique em Ok em ambas as telas
https://static-cdn.m5stack.com/resource/arduino/package_m5stack_index.json

Vá em Tools >  Boards Manager, no campo de pesquisa digite M5Stack, selecione o M5Stack by M5Stack Oficial e clique em Install, ele vai demorar um pouco

Após a instalação vamos em Sketch > Include Library e procure por M5Unified e clique em Install

Vá em Tools > Boards > e na lista abaixo selecione M5Cardputer

Vá em Tools > Ports > e selecione a porta que o Arduino IDE reconheceu 

Envie o código vazio para ver a conectividade,  clicando na seta para direitra.

```C++
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

Dando tudo certo agora cole o código abaixo do nosso Hello World

```C++
void setup() {
    // Inicialização mínima recomendada para o Cardputer
    auto cfg = M5.config();
    M5.begin(cfg);
    
    // Liga o barramento da tela primeiro
    M5.Lcd.begin();
    M5.Lcd.setRotation(1);
    M5.Lcd.setBrightness(100);
    
    // Pinta a tela de azul escuro para sabermos que o código rodou
    M5.Lcd.fillScreen(BLUE); 
    
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 30);
    M5.Lcd.println("Hello World");
    
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(10, 70);
    M5.Lcd.println("Se voce esta vendo isso,");
    M5.Lcd.println("o hardware esta vivo.");
}

void loop() {
    // Mantém o processador ocupado
    delay(1000);
}
```
