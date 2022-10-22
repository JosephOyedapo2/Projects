package textviewer;

public class CenterModifier implements Modifier {
    public CenterModifier(){}
	public Block[][] modify(Block[][] blocks, int width) {
        int i = 0;
		int[] rowLengths = new int[blocks.length];
		for (i = 0; i < blocks.length; i++) {
			rowLengths[i] = 0;
			int len = blocks[i].length;
			for (int j = 0; j < len; j++) {
				rowLengths[i] += blocks[i][j].getWidth();
			}
			Block[] newRow = new Block[len + 1];
			System.arraycopy(blocks[i],0,newRow,1,len);
			newRow[0] = new Block(newRow[1].getFontMetrics(),"");
			blocks[i] = newRow;
		}
		for (i = 0; i < blocks.length; i++) {
            if (width - (rowLengths[i] * 3/2) < 0) {
                int cleft = (width - rowLengths[i])/2;
                int cright = (width - rowLengths[i])/2;
                int j = blocks.length - 1;
                blocks[i][0].setWidth(cleft);
                blocks[j][j-1].setWidth(cright);
            } else {
                blocks[i][0].setWidth(width - (rowLengths[i] * 3/2));
            }
        }
		return blocks;
    }
}
