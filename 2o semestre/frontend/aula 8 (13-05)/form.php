<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f0f0f0;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        .main {
            background-color: #fff;
            border-radius: 20px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            padding: 20px;
            width: 400px;
            max-width: 90%;
        }

        .main form {
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .main input[type="text"],
        .main input[type="number"] {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
            border: 1px solid #ccc;
            border-radius: 5px;
            box-sizing: border-box;
        }

        .main input[type="submit"] {
            background-color: #4CAF50;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }

        .main input[type="submit"]:hover {
            background-color: #45a049;
        }

        .main label {
            margin-bottom: 5px;
            font-weight: bold;
        }
    </style>
</head>

<body>
    <?php
    if (@$_REQUEST['enviar']) {
        $handle = fopen("form.txt", "a+");
        $nome = $_GET['nome'];
        $curso = $_GET['curso'];
        $idade = $_GET['idade'];
        $valor = $_GET['valor'];
        $sexo = $_GET['sexo'];
        $content = $nome . "|" . $curso . "|" . $idade . "|" . $valor . "|" . $sexo . "\n";
        if (strlen($content) ==  fwrite($handle, $content)) {
            echo "gravado com sucesso";
        }
        fclose($handle);
    }
    ?>

    <div class="main">
        <form action="#" method="get">
            <label for="nome">Nome:</label>
            <input type="text" id="nome" name="nome">
            <label for="curso">Curso:</label>
            <input type="text" id="curso" name="curso">
            <label for="idade">Idade:</label>
            <input type="number" id="idade" name="idade">
            <label for="valor">Valor mensalidade (R$):</label>
            <input type="number" id="valor" name="valor">
            <label for="sexo">Sexo:</label>
            <input type="text" id="sexo" name="sexo">
            <input type="submit" value="ENVIAR" name="enviar">
        </form>
    </div>

</body>

</html>
