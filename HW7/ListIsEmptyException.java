
/* Exception class to check if initial playlist or viewlist is empty or not */
public class ListIsEmptyException extends Exception {
    public ListIsEmptyException(String message) {
        super(message);
    }
}