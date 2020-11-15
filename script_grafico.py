import matplotlib.pyplot as plt

arquivo = input("Insira o nome do arquivo: ") #colocar o nome ou path do arquivo txt (com duas colunas sendo a primeira n e a segunda o tempo)

file = open(arquivo, "r")

datasheet = file.read().split('\n') #separa as linhas

datasheet.pop(-1) #retira o \n extra q tem no final

datasheet_keys = []
datasheet_values = []

for i in range(0, len(datasheet)): #gera os pares ordenados e separa em dominio e imagem
    datasheet[i] = datasheet[i].split(' ')
    datasheet_keys.append(int(datasheet[i][0]))
    datasheet_values.append(float(datasheet[i][1]))

print(datasheet_keys)
print(datasheet_values)

plt.figure(figsize=(20,20))
plt.ticklabel_format(style='plain', axis='both', scilimits=(0,0))
plt.plot(datasheet_keys, datasheet_values, label=arquivo[:-4])
plt.legend()
plt.ylabel("Tempo em segundos")
plt.xlabel("Numero de elementos n do array X")
plt.savefig(arquivo[:-4] + ".png")
plt.show()