import java.io.File;

public class CreateFolders {
    public static void main(String[] args) {
        for (int i = 0; i <= 90; i++) {
            String folderName = "day" + i;
            File folder = new File(folderName);
            if (folder.mkdir()) {
                System.out.println("Created folder: " + folderName);
            } else {
                System.out.println("Failed to create folder: " + folderName);
            }
        }
        System.out.println("All folders created successfully!");
    }
}
