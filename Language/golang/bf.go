package main

import (
	"bufio"
	"errors"
	"fmt"
	"io/ioutil"
	"os"
)

type Instruction struct {
	operator uint16
	operand  uint16
}

const (
	incrementDataPointer = iota
	deIncrementDataPointer
	incrementValue
	deIncrementValue
	opOutput
	opInput
	loopIndexForward
	loopIndexBackward
)

type Compailer struct {
	dataSize     int
	fileName     string
	instructions string
}

func (compailer *Compailer) setFileName(fileName string) {
	compailer.fileName = fileName
}

func (compailer *Compailer) getFileName() string {
	return compailer.fileName
}

func (compailer *Compailer) openFile(fileName string) string {
	compailer.fileName = fileName
	instructions, err := ioutil.ReadFile(compailer.fileName)

	if err != nil {
		panic("Error reading " + compailer.fileName)
	}
	compailer.instructions = string(instructions)
	return compailer.instructions
}

func (compailer *Compailer) setInstructions(instructions string) {
	compailer.instructions = instructions
}

func (compailer *Compailer) getInstructions() string {
	return compailer.instructions
}

func (compailer *Compailer) compileBF(input string) (program []Instruction, err error) {
	var pc, loopPointCounter uint16 = 0, 0
	loopStack := make([]uint16, 0)

	for _, c := range input {
		switch c {
		case '>':
			program = append(program, Instruction{incrementDataPointer, 0})
		case '<':
			program = append(program, Instruction{deIncrementDataPointer, 0})
		case '+':
			program = append(program, Instruction{incrementValue, 0})
		case '-':
			program = append(program, Instruction{deIncrementValue, 0})
		case '.':
			program = append(program, Instruction{opOutput, 0})
		case ',':
			program = append(program, Instruction{opInput, 0})
		case '[':
			program = append(program, Instruction{loopIndexForward, 0})
			loopStack = append(loopStack, pc)
		case ']':
			if len(loopStack) == 0 {
				return nil, errors.New("Compilation error.")
			}

			loopPointCounter = loopStack[len(loopStack)-1]
			loopStack = loopStack[:len(loopStack)-1]
			program = append(program, Instruction{loopIndexBackward, loopPointCounter})
			program[loopPointCounter].operand = pc

		default:
			pc--
		}
		pc++
	}
	if len(loopStack) != 0 {
		return nil, errors.New("Compilation error.")
	}
	return
}

func (compailer *Compailer) executeBF(program []Instruction) {

	data := make([]int16, compailer.dataSize)
	var dataPointer uint16 = 0
	reader := bufio.NewReader(os.Stdin)

	for pc := 0; pc < len(program); pc++ {
		switch program[pc].operator {
		case incrementDataPointer:
			dataPointer++
		case deIncrementDataPointer:
			dataPointer--
		case incrementValue:
			data[dataPointer]++
		case deIncrementValue:
			data[dataPointer]--
		case opOutput:
			fmt.Printf("%c", data[dataPointer])
		case opInput:
			read_val, _ := reader.ReadByte()
			data[dataPointer] = int16(read_val)
		case loopIndexForward:
			if data[dataPointer] == 0 {
				pc = int(program[pc].operand)
			}
		case loopIndexBackward:
			if data[dataPointer] > 0 {
				pc = int(program[pc].operand)
			}
		default:
			panic("Unknown operator.")
		}
	}
}

func main() {

	compailer := Compailer{dataSize: 65535}
	instructions := compailer.openFile("hw.bf")
	program, err := compailer.compileBF(instructions)

	if err != nil {
		fmt.Println(err)
		return
	}
	compailer.executeBF(program)
}
