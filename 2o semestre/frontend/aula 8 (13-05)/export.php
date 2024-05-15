<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
<!-- 
"r" (read):

Abre o arquivo para leitura apenas.
Coloca o ponteiro do arquivo no início do arquivo.

"w" (write):

Abre o arquivo para escrita apenas.
Trunca o arquivo para zero comprimento, ou cria um arquivo novo se ele não existir.
Coloca o ponteiro do arquivo no início do arquivo.
Se o arquivo não existir, tenta criá-lo.

"a" (append):

Abre o arquivo para escrita apenas.
Coloca o ponteiro do arquivo no final do arquivo.
Se o arquivo não existir, tenta criá-lo.
Os dados serão adicionados ao final do arquivo.
-->
    <?php
    $abrir  = fopen("backup.txt","a");
    $escreva = fwrite($abrir,"linha inserida no arqivo \nSegunda linha do arq\nterceira\n");
    fclose($abrir);
    ?>
</body>
</html>