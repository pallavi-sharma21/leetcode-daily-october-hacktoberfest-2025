func pacificAtlantic(islandGrid [][]int) [][]int {
	if len(islandGrid) == 0 || len(islandGrid[0]) == 0 {
		return [][]int{}
	}

	numberOfRows := len(islandGrid)
	numberOfColumns := len(islandGrid[0])

	canFlowToPacific := make([][]bool, numberOfRows)
	canFlowToAtlantic := make([][]bool, numberOfRows)

	for i := 0; i < numberOfRows; i++ {
		canFlowToPacific[i] = make([]bool, numberOfColumns)
		canFlowToAtlantic[i] = make([]bool, numberOfColumns)
	}
	for column := 0; column < numberOfColumns; column++ {
		exploreInland(0, column, canFlowToPacific, islandGrid)
		exploreInland(numberOfRows-1, column, canFlowToAtlantic, islandGrid)
	}

	for row := 0; row < numberOfRows; row++ {
		exploreInland(row, 0, canFlowToPacific, islandGrid)
		exploreInland(row, numberOfColumns-1, canFlowToAtlantic, islandGrid)
	}

	var sharedCells [][]int
	for row := 0; row < numberOfRows; row++ {
		for column := 0; column < numberOfColumns; column++ {
			if canFlowToPacific[row][column] && canFlowToAtlantic[row][column] {
				sharedCells = append(sharedCells, []int{row, column})
			}
		}
	}
	return sharedCells
}

func exploreInland(row, column int, isReachable [][]bool, islandGrid [][]int) {
	isReachable[row][column] = true

	numberOfRows := len(islandGrid)
	numberOfColumns := len(islandGrid[0])
	possibleDirections := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

	for _, direction := range possibleDirections {
		nextRow := row + direction[0]
		nextColumn := column + direction[1]

		if nextRow < 0 || nextRow >= numberOfRows || nextColumn < 0 || nextColumn >= numberOfColumns {
			continue
		}
		if isReachable[nextRow][nextColumn] {
			continue
		}
		if islandGrid[nextRow][nextColumn] >= islandGrid[row][column] {
			exploreInland(nextRow, nextColumn, isReachable, islandGrid)
		}
	}
}
