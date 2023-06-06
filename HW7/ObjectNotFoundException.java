
/* Exception class to check if objects that passed as arguments is in the list or not */
public class ObjectNotFoundException extends Exception {
    public ObjectNotFoundException(String message) {
        super(message);
    }
}