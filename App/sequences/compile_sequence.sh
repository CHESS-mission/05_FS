# Compile texte sequence files to binary
# Usage ./compile_sequence.bin <text_sequence_file>
../../fprime/Gds/bin/run_seqgen.sh "$1" -d ../build-artifacts/Linux/dict/AppTopologyAppDictionary.xml
# Once compiled, move the binary in the application executable root to use it with CmdSeq
