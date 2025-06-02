import re

# Your input species map — paste it below
input_species_block = """
#define SPECIES_UXIE 0x215
#define SPECIES_MESPRIT 0x216
#define SPECIES_AZELF 0x217
#define SPECIES_DIALGA 0x218
#define SPECIES_PALKIA 0x219
#define SPECIES_HEATRAN 0x21A
#define SPECIES_REGIGIGAS 0x21B
#define SPECIES_GIRATINA 0x21C
#define SPECIES_CRESSELIA 0x21D
#define SPECIES_PHIONE 0x21E
#define SPECIES_MANAPHY 0x21F
#define SPECIES_DARKRAI 0x220
#define SPECIES_SHAYMIN 0x221
#define SPECIES_ARCEUS 0x222
#define SPECIES_VICTINI 0x223
"""

# Set your starting index for the array
start_index = 0


# Regex pattern to extract species name
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)")

# Clean and capitalize species names (handle underscores properly)
def format_species_name(raw):
    return ''.join(part.capitalize() for part in raw.lower().split('_'))

lines = input_species_block.strip().splitlines()

for i, line in enumerate(lines):
    match = pattern.search(line)
    if match:
        species_name = format_species_name(match.group(1))
        index = start_index + i
        print(f"\t&gFollowerMonGfxTable2[{index}], // {species_name}")
