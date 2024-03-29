<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Processamento do Formulário</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        .container {
            max-width: 600px;
            margin: 0 auto;
            padding: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
            background-color: #f9f9f9;
        }
        .container h2 {
            text-align: center;
        }
        .info {
            margin-bottom: 10px;
        }
        .info label {
            font-weight: bold;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Dados do Formulário</h2>
        <?php
        // Verifica se o formulário foi enviado
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            // Abre ou cria o arquivo para escrita
            $arquivo = fopen("dados_formulario.txt", "a");
            if ($arquivo === false) {
                die("Não foi possível abrir o arquivo para escrita.");
            }
            // Prepara os dados para escrita no arquivo
            $dados = "Nome: " . $_POST['nome'] . "\n";
            $dados .= "E-mail: " . $_POST['email'] . "\n";
            $dados .= "Telefone: " . $_POST['telefone'] . "\n";
            $dados .= "Assunto: " . $_POST['assunto'] . "\n";
            $dados .= "Motivo do Contato: " . $_POST['motivo_contato'] . "\n";
            $dados .= "Mensagem: " . $_POST['mensagem'] . "\n";
            $dados .= "Endereço: " . $_POST['endereco'] . "\n";
            $dados .= "Cidade: " . $_POST['cidade'] . "\n";
            $dados .= "Estado: " . $_POST['estado'] . "\n";
            $dados .= "Código Postal: " . $_POST['codigo_postal'] . "\n";
            $dados .= "Data de Nascimento: " . $_POST['data_nascimento'] . "\n";
            $dados .= "Gênero: " . $_POST['genero'] . "\n";
            $dados .= "Preferência de Contato: " . $_POST['preferencia_contato'] . "\n";
            // Adicione aqui os demais campos do formulário

            // Escreve os dados no arquivo
            if (fwrite($arquivo, $dados) === false) {
                die("Não foi possível escrever no arquivo.");
            }
            fclose($arquivo);

            // Exibe os dados na tela
            echo "<div class='info'><label for='nome'>Nome:</label> " . htmlspecialchars($_POST['nome']) . "</div>";
            echo "<div class='info'><label for='email'>E-mail:</label> " . htmlspecialchars($_POST['email']) . "</div>";
            echo "<div class='info'><label for='telefone'>Telefone:</label> " . htmlspecialchars($_POST['telefone']) . "</div>";
            echo "<div class='info'><label for='assunto'>Assunto:</label> " . htmlspecialchars($_POST['assunto']) . "</div>";
            echo "<div class='info'><label for='motivo_contato'>Motivo do Contato:</label> " . htmlspecialchars($_POST['motivo_contato']) . "</div>";
            echo "<div class='info'><label for='mensagem'>Mensagem:</label> " . htmlspecialchars($_POST['mensagem']) . "</div>";
            echo "<div class='info'><label for='endereco'>Endereço:</label> " . htmlspecialchars($_POST['endereco']) . "</div>";
            echo "<div class='info'><label for='cidade'>Cidade:</label> " . htmlspecialchars($_POST['cidade']) . "</div>";
            echo "<div class='info'><label for='estado'>Estado:</label> " . htmlspecialchars($_POST['estado']) . "</div>";
            echo "<div class='info'><label for='codigo_postal'>Código Postal:</label> " . htmlspecialchars($_POST['codigo_postal']) . "</div>";
            echo "<div class='info'><label for='data_nascimento'>Data de Nascimento:</label> " . htmlspecialchars($_POST['data_nascimento']) . "</div>";
            echo "<div class='info'><label for='genero'>Gênero:</label> " . htmlspecialchars($_POST['genero']) . "</div>";
            echo "<div class='info'><label for='preferencia_contato'>Preferência de Contato:</label> " . htmlspecialchars($_POST['preferencia_contato']) . "</div>";
            echo "<a class='download-btn' href='dados_formulario.txt' download>Download dos Dados</a>";// Adicione aqui os demais campos do formulário

        } else {
            echo "<p>Nenhum dado recebido.</p>";
        }
        ?>
    </div>
</body>
</html>
