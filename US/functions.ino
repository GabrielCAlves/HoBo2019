// Detectar obstáculo
int usDetect(Ultrasonic us) {

  int media = 0;
  for (int i = 0; i < 7; i++) {

    int leitura = us.read();
    media += leitura;

    delay(3);

  }

  return int(media/7);

}
