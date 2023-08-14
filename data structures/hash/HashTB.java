import java.util.Arrays;
import java.util.Scanner;

class HashTableLinear {
	
	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int tamanho = Integer.parseInt(scan.nextLine());
		TabelaHash tabela = new TabelaHash(tamanho);

		Integer key;
		String value;
		String entrada[];
		String operacao = "";

		while (!operacao.equals("end")) {
			entrada = scan.nextLine().split(" ");
			operacao = entrada[0];

			switch (operacao) {
			case "put":
				key = Integer.parseInt(entrada[1]);
				value = entrada[2];
				System.out.println(tabela.put(key, value));
				break;

			case "remove":
				key = Integer.parseInt(entrada[1]);
				System.out.println(tabela.remove(key));
				break;

			case "keys":
				System.out.println(Arrays.toString(tabela.keys()));
				break;

			case "values":
				System.out.println(Arrays.toString(tabela.values()));
				break;
			}

		}
		scan.close();
	}
}

class TabelaHash {

	private Pair[] tabela;
	private int elementos;

	public TabelaHash(int tamanho) {
		this.tabela = new Pair[tamanho];
	}

	public String put(Integer key, String value) {
		if (!this.isFull()) {
			int i = 0;
			int j;
			boolean inseriu = false;
			while (i < this.tabela.length && !inseriu) {
				j = this.funcaoHash(key, i);
				if (this.tabela[j] != null && this.tabela[j].getKey() == key) {

					this.remove(key);

				}
				if (this.tabela[j] == null || this.tabela[j].isDeleted()) {
					Pair par = new Pair(key, value);
					this.tabela[j] = par;
					this.elementos++;
					inseriu = true;
				}
				i++;
			}

		}
		return this.toString();
	}

	public String remove(Integer key) {
		if (!isEmpty()) {
			int i = 0;
			int j;
			boolean removeu = false;
			while (i < this.tabela.length && !removeu) {
				j = this.funcaoHash(key, i);
				if (this.tabela[j] != null && this.tabela[j].getKey().equals(key)) {
					this.tabela[j].delete();
					this.elementos--;
					removeu = true;
				}
				i++;
			}
		}
		return this.toString();
	}

	public Integer[] keys() {
		Integer[] keys = new Integer[this.elementos];
		int index = 0;
		for (int i = 0; i < this.tabela.length; i++) {
			if (this.tabela[i] != null && !this.tabela[i].isDeleted()) {
				keys[index++] = this.tabela[i].getKey();
			}

		}
		Arrays.sort(keys);
		return keys;
	}

	public String[] values() {
		String[] values = new String[this.elementos];
		int index = 0;
		for (int i = 0; i < this.tabela.length; i++) {
			if (this.tabela[i] != null && !this.tabela[i].isDeleted()) {
				values[index++] = this.tabela[i].getValue();
			}
		}
		Arrays.sort(values);
		return values;
	}

	public boolean isFull() {
		return this.elementos == this.tabela.length;
	}

	public boolean isEmpty() {
		return this.elementos == 0;
	}

	@Override
	public String toString() {
		return Arrays.toString(this.tabela);
	}

	public int funcaoHash(Integer k, int i) {
		return (k + i) % this.tabela.length;
	}

}

class Pair {

	private Integer key;
	private String value;
	private boolean deleted;

	public Pair(Integer key, String value) {

		this.key = key;
		this.value = value;
		this.deleted = false;
	}

	public boolean isDeleted() {
		return deleted;
	}

	public void delete() {
		this.deleted = true;
	}

	public Integer getKey() {
		return this.key;
	}

	public String getValue() {
		return this.value;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pair other = (Pair) obj;
		if (key == null) {
			if (other.key != null)
				return false;
		} else if (!key.equals(other.key))
			return false;
		return true;
	}

	@Override
	public String toString() {
		String result = null;
		if (!deleted) {
			result = "<" + this.key + ", " + this.value + ">";
		}
		return result;
	}
}
