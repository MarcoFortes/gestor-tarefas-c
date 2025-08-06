# ======================================================
# Makefile - Sistema de Gerenciamento de Tarefas
# ======================================================

#--------------- [CONFIGURAÇÕES BÁSICAS] ---------------
# Diretório de saída para os arquivos compilados
BUILD_DIR := build

# Arquivos fonte (todos os .c no diretório atual)
SOURCES = *.c

# Diretórios de cabeçalhos (inclui o diretório atual)
HEADERS = -I.

#--------------- [REGRAS PRINCIPAIS] ---------------
# Requisitos:
# - Todos os arquivos .c devem estar atualizados
# - Diretório build deve existir	

$(BUILD_DIR)/main: $(wildcard $(SOURCES))
	@echo "[COMPILANDO] Criando executavel principal..."
	gcc -o $(BUILD_DIR)/main $(SOURCES) $(HEADERS)
	@echo "[SUCESSO] Executavel gerado em $(BUILD_DIR)/main"

# Executa o programa compilado
# Depende da regra build/main para garantir que o programa está atualizado
run: $(BUILD_DIR)/main
	./$(BUILD_DIR)/main.exe

#--------------- [UTILITARIOS] ---------------

.PHONY: help
help:
	@echo "=== AJUDA ==="
	@echo "make           - Compila o programa"
	@echo "make run       - Compila e executa"
	@echo "make help      - Mostra esta mensagem"


# [NOTAS PARA DESENVOLVEDORES] ------------------------
# 1. Estrutura esperada do projeto:
#    - / (raiz)
#      |- Makefile
#      |- *.c (arquivos fonte)
#      |- *.h (arquivos de cabeçalho)
#      |- /build (criada nanualmente)
#      |- /prototypes (pasta dos antigos heades e arquivos fontes)
#
#
# 3. Padrões recomendados:
#    - Sempre use $(BUILD_DIR) para outputs
#    - Mantenha o .PHONY atualizado
# =====================================================