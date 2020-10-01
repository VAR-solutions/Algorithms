import pyhash

fnv_hasher = pyhash.fnv1_32()
murmur_hasher = pyhash.murmur3_32()

# Calculate output of FNV and Murmur hash for Pikachu and Charmander.
fnv_hash_pikachu = fnv_hasher("Pikachu") % 20
murmur_hash_pikachu = murmur_hasher("Pikachu") % 20

fnv_hash_charmander = fnv_hasher("Charmander") % 20
murmur_hash_charmander = murmur_hasher("Charmander") % 20

# Print the output of FNV and Murmur hashes.
print("FNV hash output for Pikachu: " + str(fnv_hash_pikachu))
print("Murmur hash output for Pikachu: " + str(murmur_hash_pikachu))

print("FNV hash output for Charmander: " + str(fnv_hash_charmander))
print("Murmur hash output for Charmander: " + str(murmur_hash_charmander))

# Flip the bits of bit_vector in the corresponding locations from above hashes.
bit_vector[fnv_hash_pikachu] = 1
bit_vector[murmur_hash_pikachu] = 1

bit_vector[fnv_hash_charmander] = 1
bit_vector[murmur_hash_charmander] = 1

print(bit_vector)


# Calculate output of FNV and Murmur hash for Bulbasaur.
fnv_hash_bulbasaur = fnv_hasher("Bulbasaur") % 20
murmur_hash_bulbasaur = murmur_hasher("Bulbasaur") % 20

# Print the FNV and Murmur hashes of Bulbasaur.
print("FNV hash output for Bulbasaur: " + str(fnv_hash_bulbasaur))
print("Murmur hash output for Bulbasaur: " + str(murmur_hash_bulbasaur))


bit_vector[fnv_hash_bulbasaur] = 1
bit_vector[murmur_hash_bulbasaur] = 1
print(bit_vector)


# 150 of the 151 Pokemon (excluding Pidgey)
caught_pokemon = ["Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard", 
                  "Squirtle", "Wartortle", "Blastoise", "Caterpie", "Metapod", "Butterfree", "Weedle", 
                  "Kakuna", "Beedrill", "Pidgeotto", "Pidgeot", "Rattata", "Raticate", "Spearow", "Fearow", 
                  "Ekans", "Arbok", "Pikachu", "Raichu", "Sandshrew", "Sandslash", "Nidoran (female)", "Nidorina",
                  "Nidoqueen", "Nidoran (male)", "Nidorino", "Nidoking", "Clefairy", "Clefable", "Vulpix", 
                  "Ninetales", "Jigglypuff", "Wigglytuff", "Zubat", "Golbat", "Oddish", "Gloom", "Vileplume", 
                  "Paras", "Parasect", "Venonat", "Venomoth", "Diglet", "Dugtrio", "Meowth", "Persian", "Psyduck",
                  "Golduck", "Mankey", "Primeape", "Growlithe", "Arcanine", "Poliwag", "Poliwhirl", "Poliwrath",
                  "Abra", "Kadabra", "Alakazam", "Machop", "Machoke", "Machamp", "Bellsprout", "Weepinbell", 
                  "Victreebel", "Tentacool", "Tentacruel", "Geodude", "Graveler", "Golem", "Ponyta", "Rapidash",
                  "Slowpoke", "Slowbro", "Magnemite", "Magneton", "Farfetc'd", "Doduo", "Dodrio", "Seel",
                  "Dewgong", "Grimer", "Muk", "Shellder", "Cloyster", "Gastly", "Haunter", "Gengar", "Onyx",
                  "Drowzee", "Hypno", "Krabby", "Kingler", "Voltorb", "Electrode", "Exeggcute", "Exeggutor", 
                  "Cubone", "Marowak", "Hitmonlee", "Hitmonchan", "Lickitung", "Koffing", "Weezing", "Rhyhorn", 
                  "Rhydon", "Chansey", "Tangela", "Kangaskhan", "Horsea", "Seadra", "Goldeen", "Seaking", 
                  "Staryu", "Starmie", "Mr. Mime", "Scyther", "Jynx", "Electabuzz", "Magmar", "Pinsir", "Tauros",
                  "Magikarp", "Gyrados", "Lapras", "Ditto", "Eevee", "Vaporeon", "Jolteon", "Flareon", "Porygon", 
                  "Omanyte", "Omastar", "Kabuto", "Kabutops", "Aerodactyl", "Snorlax", "Articuno", "Zapdos",
                  "Moltres", "Dratini", "Dragonair", "Dragonite", "Mewtwo", "Mew" ]
pokedex_bloom_filter = [0] * 20

# Update the Bloom filter positions of the bit vector.
for pokemon in caught_pokemon:
    fnv_hash = fnv_hasher(pokemon) % 20
    murmur_hash = murmur_hasher(pokemon) % 20
    
    pokedex_bloom_filter[fnv_hash] = 1
    pokedex_bloom_filter[murmur_hash] = 1
    
# The Pokedex Bloom filter.    
print(pokedex_bloom_filter)



fnv_hash_pidgey = fnv_hasher("Pidgey") % 20
murmur_hash_pidgey = murmur_hasher("Pidgey") % 20

print(pokedex_bloom_filter[fnv_hash_pidgey])
print(pokedex_bloom_filter[murmur_hash_pidgey])

from __future__ import division
import math

# Total number of Pokemon in the Blue/Red universe.
n = 151
# Selecting parameter m to be larger than what we require. 
m = 1000
# Calculating the optimal k to determine how many hash functions we should use. 
k = (m//n)*math.log(2,math.e)
print(k)

# How likely is it with the parameters n,m, and k that we encounter a false positive?
(1 - math.e**(-k*n/m))**k

